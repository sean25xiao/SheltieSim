#include <iostream>
#include <string>

#include "cpu.h"

using std::cout;
using std::endl;

int main() {
    c_cpu cpu0("CPU0");

    cout << cpu0.get_name() << endl;
    cpu0.log();

    cpu0.run();
    cpu0.log();


    return 0;
}