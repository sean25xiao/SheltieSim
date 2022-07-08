#include <iostream>
#include <bitset>   // std::biset
#include "helper.h"
#include "encoding.h"

uint32_t bits_extract(const uint32_t data, const uint32_t begin, const uint32_t end)
{
    uint32_t data_bits;
    data_bits = data << (XLEN_TOP_BIT - begin);
    data_bits = data_bits >> (XLEN_TOP_BIT - (begin - end));

    return data_bits;
}

int sign_extend()
{
    
}