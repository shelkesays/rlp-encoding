#include "inc/rlpencode.hpp"

#include <iostream>
#include <vector>

#include "inc/constants.inc"
#include "inc/utils.hpp"
#include "inc/rlpstring.hpp"


std::vector<char> RLPEncoder::EncodeLength(const int len, const int offset) {
    if (len < SINGLE_BYTE_STRING) {
        std::cout << len + offset << std::endl;
        return IntegerToBytes(len + offset);
    } else {
        const std::string hex_len_ = IntegerToHex(len);
        const int l_length_ = hex_len_.size() / 2;
        const std::string first_byte_ = IntegerToHex(offset + 55 + l_length_);
        const uint64_t number_ = HexToInteger(first_byte_);
        return IntegerToBytes(number_);
    }
}

std::vector<char> RLPEncoder::Encode(const std::vector<char> bytes_value, const int offset) {
    if(bytes_value.size() == 1 && offset == SHORT_STRING && bytes_value[0] < SHORT_STRING) {
        return bytes_value;
    } else {
        std::vector<char> encode_length = EncodeLength(bytes_value.size(), SHORT_STRING);
        encode_length.insert(encode_length.end(), bytes_value.begin(), bytes_value.end());

        return encode_length;
    }
}

std::vector<char> RLPEncoder::EncodeString(RLPString input) {
    return Encode(input.GetBytes(), SHORT_STRING);
}

std::vector<char> RLPEncoder::EncodeString(const std::string input) {
    RLPString rlp_str_ = RLPString::Create(input);
    return EncodeString(rlp_str_);
}
