#ifndef RLP_RLP_ENCODE_H
#define RLP_RLP_ENCODE_H

#include <vector>
#include <iostream>

#include "rlpstring.hpp"

class RLPEncoder {
    private:
        static std::vector<char> EncodeLength(const int len, const int offset);
        static std::vector<char> Encode(const std::vector<char> bytes_value, const int offset);

    public:
        static std::vector<char> EncodeString(RLPString input);
        static std::vector<char> EncodeString(const std::string input);
};

#endif