#ifndef RLP_RLP_DECODE_H
#define RLP_RLP_DECODE_H

#include <iostream>
#include <vector>

class RLPDecoder
{
private:
    static std::vector<uint64_t> Decode(const std::vector<uint64_t> bytes_input);
public:
    static std::string DecodeString(const std::string& input);
};

#endif