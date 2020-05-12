#include "inc/rlpencode.hpp"

#include "inc/constants.inc"
#include "inc/utils.hpp"
#include "inc/rlpstring.hpp"


std::vector<char> RLPEncoder::EncodeLength(const int len, const int offset) {
    if (len <= SINGLE_BYTE_STRING) {
        return IntegerToBytes(len + offset);
    } else {
        const std::string hex_len_ = IntegerToHex(len);
        const int l_length_ = hex_len_.size() / 2;
        const uint64_t number_ = offset + SINGLE_BYTE_STRING + l_length_;
        return IntegerToBytes(number_);
    }
}

std::vector<char> RLPEncoder::Encode(const std::vector<char> bytes_value, const int offset) {
    std::vector<char> encode_length_;
    if (bytes_value.empty()) {
        encode_length_.push_back(NON_VALUE_STRING);
    } else if(bytes_value.size() == 1 && bytes_value[0] <= SHORT_STRING) {
        encode_length_ = bytes_value;
    } else {
        encode_length_ = EncodeLength(bytes_value.size(), SHORT_STRING);
        encode_length_.insert(encode_length_.end(), bytes_value.begin(), bytes_value.end());
    }

    return encode_length_;
}

std::vector<char> RLPEncoder::EncodeString(RLPString input) {
    return Encode(input.GetBytes(), SHORT_STRING);
}

std::vector<char> RLPEncoder::EncodeString(const std::string input) {
    RLPString rlp_str_ = RLPString::Create(input);
    return EncodeString(rlp_str_);
}
