#ifndef RLP_RLP_STRING_H
#define RLP_RLP_STRING_H

#include <iostream>
#include <vector>
// #include <stdint.h>

class RLPString {
    private:
        std::vector<char> value;
        RLPString(const std::vector<char> value);

    public:
        std::vector<char> GetBytes();
        std::string AsHexString();
        static RLPString Create(const std::vector<char> input);
        static RLPString Create(const char input);
        static RLPString Create(const uint64_t input);
        static RLPString Create(const long input);
        static RLPString Create(const std::string input);
};

#endif