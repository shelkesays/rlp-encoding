#ifndef RLP_RLP_DECODE_H
#define RLP_RLP_DECODE_H

#include <iostream>
#include <vector>

class RLPDecoder
{
private:
    static std::string Decode(const std::vector<char> bytes_input);
public:
    static std::string DecodeString(const std::string& input);
};

#endif