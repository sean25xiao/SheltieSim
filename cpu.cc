#include <iostream>
#include <string>
#include <fstream>  // std::ifstream
#include <bitset>   // std::biset
#include "cpu.h"
#include "encoding.h"

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
    for (int i = 0; i < 100; i++)
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
    return true;
}

uint32_t c_cpu::fetch()
{
    bool read_success;
    read_success = readBinFile("./obj/add-addi.bin");
    if (!read_success)
    {
        std::cerr << "Error: readBinFile failed" << endl;
        exit(1);
    }

    uint32_t index = pc;  // pc = 0 in reset

    uint32_t instr =   fake_mem[index]
                    | (fake_mem[index+1] << 8)
                    | (fake_mem[index+2] << 16)
                    | (fake_mem[index+3] << 24);

    std::bitset<32> x(instr);

    cout << "fetch(): instruction = " << x << endl;

    return instr;
}

void c_cpu::decode(const uint32_t instr)
{
    cout << "decode(): decode starts" << endl;

    uint32_t opcode = bits_extract(instr, 0, 6);
    std::bitset<7> x(opcode);

    cout << "fetch(): instruction = " << x << endl;

    switch (opcode)
    {
        case OP_IMM:
            cout << "decode(): it's I-Type Instruction" << endl;
            break;
        default:
            cout << "decode(): Error, non-instruction type is falled" << endl;
            break;
    }
}

void c_cpu::run()
{
    decode(fetch());
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

uint32_t bits_extract(const uint32_t data, const uint32_t begin, const uint32_t end)
{
    uint32_t data_bits;
    data_bits = data << (XLEN_TOP_BIT - end);
    data_bits = data_bits >> (XLEN_TOP_BIT - (end - begin));

    return data_bits;
}