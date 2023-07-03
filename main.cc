#include <iostream>
#include <string>

#include "cpu.h"

using std::cout;
using std::endl;

int main() {
    c_cpu cpu0("CPU0");

    cout << cpu0.get_name() << endl;
    cpu0.log();
    cpu0.set_binfile("./obj/rv32i-addi.bin");

    cpu0.run();
    cpu0.log();

    c_cache cache0("ICACHE0");
    cout << cache0.get_name() << endl;


    return 0;
}