#include <iostream>
#include <string>
#include <fstream>  // std::ifstream
#include <bitset>   // std::biset
#include "cache.h"

c_cache::c_cache()
    :name{"None"} {

};

c_cache::c_cache(std::string _name)
    :name{input_name} {
    //reset();
};

bool c_cache::set_name(const std::string _name) {
    this->name = name;
    if (this->name == "None")
        return false;

    return true;
};