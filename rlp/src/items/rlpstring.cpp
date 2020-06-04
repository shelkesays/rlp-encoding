#include "rlpstring.hpp" 

#include "utils.hpp"

RLPString::RLPString(const buffer_t input) {
    _bytes = input;
}

buffer_t RLPString::GetBytes() {
    return _bytes;
}

std::string RLPString::AsHexString() {
    return BytesToString(_bytes);
}

RLPString RLPString::Create(const buffer_t input) {
    return RLPString(input);
}

RLPString RLPString::Create(const uint64_t input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(EmptyByte());
    }
    buffer_t bytes_;
    bytes_.push_back(input);
    return RLPString(bytes_);
}

RLPString RLPString::Create(const char input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(EmptyByte());
    }
    buffer_t bytes_ = IntegerToBytes(input);
    return RLPString(bytes_);
}

RLPString RLPString::Create(const long input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(EmptyByte());
    }
    return Create((uint64_t)input);
}

RLPString RLPString::Create(const std::string input) {
    if (input.empty()) {
        return Create(EmptyByte());
    }
    buffer_t bytes_ = StringToBytes(StringToHex(input));
    return RLPString(bytes_);
}
