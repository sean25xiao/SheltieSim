#include <iostream>
#include <string>
#include <fstream>  // std::ifstream
#include <bitset>   // std::biset
#include "cpu.h"
#include "encoding.h"
#include "helper.h"

#define FAKE_MEM_CAP 1000

c_cpu::c_cpu()
    :name{"None"} {

};

c_cpu::c_cpu(std::string input_name)
    :name{input_name} {
    reset();
};

void c_cpu::reset(void) 
{
    // Reset all registers to zeros
    pc = 0;
    for (int i = 0; i < 32; i++)
    {
        regs[i] = 0;
    }

    // Clear all fake mem, and initialize to 0s
    fake_mem.clear();
    for (int i = 0; i < FAKE_MEM_CAP; i++)
    {
        fake_mem.push_back(0);
    }
};

bool c_cpu::set_name(std::string name) {
    this->name = name;
    if (this->name == "None")
        return false;

    return true;
};

bool c_cpu::readBinFile(const char* filename)
{
    std::streampos fileSize;
    std::ifstream  in_file(filename, std::ios::binary);
    if (!in_file)
    {
        std::cerr << "Error: Binary File Opened Fail" << endl;
        return false;
    }

    // get its size
    in_file.seekg(0, std::ios::end); // Set the pos to the end
    fileSize = in_file.tellg(); // Returns the position of the current char
    in_file.seekg(0, std::ios::beg); // Set the pos to the beginning

    // read the data
    //std::vector<BYTE> binData(fileSize);
    in_file.read((char*) &fake_mem[0], fileSize);
    pc_end = (uint32_t)fileSize-4;  // C++ https://www.cplusplus.com/reference/istream/istream/tellg/ it can be converted to/from integral types
    cout << "pc_end is " << pc_end << endl;
    return true;
}

uint32_t c_cpu::fetch()
{
    

    uint32_t index = pc;  // pc = 0 in reset

    uint32_t instr =   fake_mem[index]
                    | (fake_mem[index+1] << 8)
                    | (fake_mem[index+2] << 16)
                    | (fake_mem[index+3] << 24);

    std::bitset<32> x(instr);

    cout << "fetch(): instruction = " << x << endl;

    return instr;
}

c_cpu::operand_t c_cpu::decode(const uint32_t instr)
{
    cout << "decode(): decode starts" << endl;

    operand_t operands;

    uint32_t opcode = bits_extract(instr, 6, 0);

    std::bitset<7> x(opcode);
    cout << "fetch(): instruction = " << x << endl;

    switch (opcode)
    {
        case OP_IMM:
            cout << "decode(): it's I-Type Instruction" << endl;
            operands.rd     = bits_extract(instr, 11, 7);
            operands.rs1    = bits_extract(instr, 19, 15);
            operands.imm    = bits_extract(instr, 31, 20);
            operands.funct3 = bits_extract(instr, 14, 12);
            operands.opcode = OP_IMM;
            break;
        default:
            cout << "decode(): Error, non-instruction type is falled" << endl;
            break;
    }

    std::bitset<5> y(operands.rd);
    cout << "decode(): rd = " << y << endl;
    std::bitset<5> yy(operands.rs1);
    cout << "decode(): rs1 = " << yy << endl;
    std::bitset<12> yyy(operands.imm);
    cout << "decode(): imm = " << yyy << endl;

    return operands;
}

void c_cpu::execute(const c_cpu::operand_t operands)
{
    uint32_t op1 = 0;
    uint32_t reg_rs2_val = 0;
    int s_imm;

    switch (operands.opcode)
    {
        case OP_IMM:
            switch(operands.funct3)
            {
                case FN_ADDI:
                        cout << "execute(): ADDI instruction" << endl;
                        op1 = regs[operands.rs1];
                        s_imm = operands.imm;
                        regs[operands.rd] = execute_addi(op1, s_imm);
                    break;
                case FN_SLTI:
                        cout << "execute(): SLTI instruction" << endl;
                        op1 = regs[operands.rs1];
                        s_imm = operands.imm;
                        regs[operands.rd] = execute_slti(op1, s_imm);
                default:
                    break;
            }
            break;
        default:
            cout << "execute(): Error, non-instruction type is falled" << endl;
            break;
    }
}

uint32_t c_cpu::execute_addi(const uint32_t op1, const int s_imm)
{
    cout << "execute_addi(): " << op1 << " + " << s_imm << " = " << (op1 + s_imm) << endl;
    return (op1 + s_imm);
}

uint32_t c_cpu::execute_slti(const uint32_t op1, const int s_imm)
{
    cout << "execute_addi(): " << op1 << " compare with " << s_imm << endl;
    return (op1 < s_imm) ? 1 : 0;
}

void c_cpu::run()
{
    bool read_success;
    read_success = readBinFile("./obj/add-addi.bin");
    if (!read_success)
    {
        std::cerr << "Error: readBinFile failed" << endl;
        exit(1);
    }
    
    while (true) 
    {
        if (pc > pc_end) {
            cout << "Reaches the end of the program, PC = " << (pc - 4) << endl;
            break;
        }

        c_cpu::operand_t operands;

        operands = decode(fetch());
        execute(operands);
        pc += 4;
    }
}

void c_cpu::log(void)
{
    std::string cpu_name;
    cpu_name = this->get_name();

    cout << "======== " << cpu_name.c_str() << " ========" << endl;
    for (int i = 0; i < 32; i++)
    {
        cout << "x" << i << " = " << regs[i] << endl;
    }
    cout << "pc = " << pc << endl;
    cout << "=====================" << endl;
};