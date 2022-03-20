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
    uint32_t regs[32];
    uint32_t pc;

    struct operand_t
    {
        /* data */
        uint8_t rd;
        uint8_t rs1;
        uint8_t rs2;
        uint8_t imm;
        uint8_t funct3;
    };
    

    std::vector<BYTE> fake_mem;

public:
    c_cpu();    // Default Constructor
    c_cpu(std::string name);
    std::string get_name() { return name; };
    bool set_name(std::string name);
    void run();

    void log();

private:
    bool readBinFile(const char* filename); // A helper function to read binary file
    uint32_t fetch();
    void decode(const uint32_t instr);
    void extract_operand(const uint32_t instr);
    void execute();

    void reset(void);
};

#endif