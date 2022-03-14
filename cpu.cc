#include <iostream>
#include <string>
#include "cpu.h"

c_cpu::c_cpu()
    :name{"None"} {

};

c_cpu::c_cpu(std::string input_name)
    :name{input_name} {
    reset();
};

void c_cpu::reset(void) 
{
    pc = 0;
    for(int i = 0; i < 32; i++)
    {
        regs[i] = 0;
    }
};

bool c_cpu::set_name(std::string name) {
    this->name = name;
    if (this->name == "None")
        return false;

    return true;
};

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