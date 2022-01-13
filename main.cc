#include <iostream>
#include <string>

#include "cpu.h"

int main() {
    c_cpu cpu0("CPU0");

    std::cout << cpu0.get_name() << std::endl;

    return 0;
}