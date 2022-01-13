#include <iostream>
#include <string>
#include "cpu.h"

c_cpu::c_cpu()
    :name{"None"} {

};

c_cpu::c_cpu(std::string input_name)
    :name{input_name} {

};

bool c_cpu::set_name(std::string name) {
    this->name = name;
    if (this->name == "None")
        return false;

    return true;
}