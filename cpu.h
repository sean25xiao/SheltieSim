#ifndef _CPU_H_
#define _CPU_H_
#include <iostream>
#include <string>

#define ZERO_REG 0;
#define XLEN 32;

using std::cout;
using std::endl;

class c_cpu {
private:
    std::string name;
    uint32_t regs[32];
    uint32_t pc;

public:
    c_cpu();    // Default Constructor
    c_cpu(std::string name);
    std::string get_name() { return name; };
    bool set_name(std::string name);

    void log();

private:
    void fetch();
    void decode();
    void execute();

    void reset(void);
};
#endif