#ifndef _CPU_H_
#define _CPU_H_
#include <iostream>
#include <string>

class c_cpu {
private:
    std::string name;
public:
    c_cpu();    // Default Constructor
    c_cpu(std::string name);
    std::string get_name() { return name; };
    bool set_name(std::string name);
};
#endif