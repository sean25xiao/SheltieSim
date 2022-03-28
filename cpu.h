#ifndef _CPU_H_
#define _CPU_H_
#include <iostream>
#include <string>
#include <vector>

typedef unsigned char BYTE;

using std::cout;
using std::endl;

class c_cpu {
private:
    std::string name;
    std::string binfile;
    uint32_t regs[32];
    uint32_t pc;
    uint32_t pc_end;

    struct operand_t
    {
        /* data */
        uint8_t rd;
        uint8_t rs1;
        uint8_t rs2;
        int     imm;
        uint8_t funct3;
        uint8_t opcode;
    };
    

    std::vector<BYTE> fake_mem;

public:
    c_cpu();    // Default Constructor
    c_cpu(std::string name);
    std::string get_name() { return name; };
    bool set_name(const std::string name);
    void set_binfile(std::string input_file);

    void run();

    void log();

private:
    bool getBinFileName();
    bool readBinFile(const std::string filename); // A helper function to read binary file
    uint32_t fetch();
    c_cpu::operand_t decode(const uint32_t instr);
    void execute(const c_cpu::operand_t operands);
    uint32_t execute_addi(const uint32_t op1, const int s_imm);
    uint32_t execute_slti(const uint32_t op1, const int s_imm);

    void reset(void);
};

#endif