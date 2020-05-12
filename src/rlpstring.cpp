#include "inc/rlpstring.hpp" 

#include "inc/utils.hpp"

RLPString::RLPString(const std::vector <unsigned char> input) {
    value = input;
}

std::vector<unsigned char> RLPString::GetBytes() {
    return value;
}

std::string RLPString::AsHexString() {
    // std::string normal_string_ = value.data();
    // return StringToHex(normal_string_);
    return BytesToString(value);
}

RLPString RLPString::Create(const std::vector <unsigned char> input) {
    return RLPString(input);
}

RLPString RLPString::Create(const unsigned char input) {
    std::vector<unsigned char> bytes_;
    bytes_.push_back(input);
    return RLPString(bytes_);
}

RLPString RLPString::Create(const uint64_t input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(EmptyByte());
    }
    std::vector<unsigned char> bytes_ = IntegerToBytes(input);
    return RLPString(bytes_);
}

RLPString RLPString::Create(const long input) {
    return Create((uint64_t)input);
}

RLPString RLPString::Create(const std::string input) {
    std::vector<unsigned char> bytes_ = StringToBytes(input);
    return RLPString(bytes_);
}
