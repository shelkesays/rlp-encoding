#include "inc/rlpstring.hpp"

// #include <iostream> 
// #include <vector> 
// #include <stdint.h> 

#include "inc/utils.hpp"

RLPString::RLPString(const std::vector <char> input) {
    value = input;
}

std::vector<char> RLPString::GetBytes() {
    return value;
}

std::string RLPString::AsHexString() {
    std::string normal_string_ = value.data();
    return StringToHex(normal_string_);
}

RLPString RLPString::Create(const std::vector <char> input) {
    return RLPString(input);
}

RLPString RLPString::Create(const char input) {
    std::vector<char> bytes_;
    bytes_.push_back(input);
    return RLPString(bytes_);
}

RLPString RLPString::Create(const uint64_t input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(EmptyByte());
    }
    std::vector<char> bytes_ = IntegerToBytes(input);
    return RLPString(bytes_);
}

RLPString RLPString::Create(const long input) {
    return Create((uint64_t)input);
}

RLPString RLPString::Create(const std::string input) {
    std::vector<char> bytes_ = StringToBytes(input);
    return RLPString(bytes_);
}
