#ifndef _cache_H_
#define _cache_H_
#include <iostream>
#include <string>
#include <vector>

class c_cache {

private:

    std::string name;

    struct cache_line {
        uint64_t tag;
        uint64_t idx;
        uint64_t offset;
    };

    uint64_t get_tag() { return tag; };
    uint64_t get_idx() { return idx; };
    uint64_t get_offset() { return offset; };

public:

    c_cache();    // Default Constructor
    c_cache(std::string _name);

    std::string get_name() const { return name; };
    bool set_name(const std::string _name);
}

#endif