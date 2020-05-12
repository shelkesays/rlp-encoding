#ifndef RLP_RLP_STRING_H
#define RLP_RLP_STRING_H

#include <iostream>
#include <vector>

class RLPString {
    private:
        std::vector<unsigned char> value;
        RLPString(const std::vector<unsigned char> value);

    public:
        std::vector<unsigned char> GetBytes();
        std::string AsHexString();
        static RLPString Create(const std::vector<unsigned char> input);
        static RLPString Create(const unsigned char input);
        static RLPString Create(const uint64_t input);
        static RLPString Create(const long input);
        static RLPString Create(const std::string input);
};

#endif