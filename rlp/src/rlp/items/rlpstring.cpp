#include "rlpstring.hpp" 

#include <utils/hex.hpp>

RLPString::RLPString(const buffer_t input) {
    _bytes = input;
}

buffer_t RLPString::GetBytes() {
    return _bytes;
}

std::string RLPString::AsHexString() {
    return utils::BytesToString(_bytes);
}

RLPString RLPString::Create(const buffer_t input) {
    return RLPString(input);
}

RLPString RLPString::Create(const uint64_t input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(utils::EmptyByte());
    }
    buffer_t bytes_;
    bytes_.push_back(input);
    return RLPString(bytes_);
}

RLPString RLPString::Create(const char input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(utils::EmptyByte());
    }
    buffer_t bytes_ = utils::IntegerToBytes(input);
    return RLPString(bytes_);
}

RLPString RLPString::Create(const long input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(utils::EmptyByte());
    }
    return Create((uint64_t)input);
}

RLPString RLPString::Create(const std::string input) {
    if (input.empty()) {
        return Create(utils::EmptyByte());
    }
    buffer_t bytes_ = utils::StringToBytes(input);
    return RLPString(bytes_);
}
