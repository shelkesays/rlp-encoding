#include "rlpstring.hpp" 

#include <utils/hex.hpp>

rlp::RLPString::RLPString(const buffer_t input) {
    _bytes = input;
}

buffer_t rlp::RLPString::GetBytes() {
    return _bytes;
}

std::string rlp::RLPString::AsHexString() {
    return utils::BytesToString(_bytes);
}

rlp::RLPString rlp::RLPString::Create(const buffer_t input) {
    return RLPString(input);
}

rlp::RLPString rlp::RLPString::Create(const uint64_t input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(utils::EmptyByte());
    }
    buffer_t bytes_;
    bytes_.push_back(input);
    return RLPString(bytes_);
}

rlp::RLPString rlp::RLPString::Create(const char input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(utils::EmptyByte());
    }
    buffer_t bytes_ = utils::IntegerToBytes(input);
    return RLPString(bytes_);
}

rlp::RLPString rlp::RLPString::Create(const long input) {
    if (input == 0) {
        // Only positive non-zero integers are allowed.
        return Create(utils::EmptyByte());
    }
    return Create((uint64_t)input);
}

rlp::RLPString rlp::RLPString::Create(const std::string input) {
    if (input.empty()) {
        return Create(utils::EmptyByte());
    }
    buffer_t bytes_ = utils::StringToBytes(input);
    return RLPString(bytes_);
}
