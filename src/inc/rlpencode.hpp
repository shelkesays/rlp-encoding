#ifndef RLP_RLP_ENCODE_H
#define RLP_RLP_ENCODE_H

#include "rlpstring.hpp"

class RLPEncoder {
    private:
        static std::vector<unsigned char> EncodeLength(const int len, const int offset);
        static std::vector<unsigned char> Encode(const std::vector<unsigned char> bytes_value, const int offset);

    public:
        static std::vector<unsigned char> EncodeString(RLPString input);
        static std::vector<unsigned char> EncodeString(const std::string input);
};

#endif