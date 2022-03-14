#ifndef _CPU_H_
#define _CPU_H_
#include <iostream>
#include <string>
#include <vector>

#define ZERO_REG 0;
#define XLEN 32;
typedef unsigned char BYTE;

using std::cout;
using std::endl;

class c_cpu {
private:
    std::string name;
    uint32_t regs[32];
    uint32_t pc;

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
    void decode();
    void execute();

    void reset(void);
};

#endif