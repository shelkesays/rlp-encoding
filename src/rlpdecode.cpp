#include "inc/rlpdecode.hpp"

#include "inc/utils.hpp"
#include "inc/rlpstring.hpp"


std::vector<uint64_t> RLPDecoder::Decode(const std::vector<uint64_t> bytes_input) {
    std::vector<uint64_t> decoded_;
    const auto first_byte_ = bytes_input[0];
    int length_ {0};

    if(first_byte_ <= 0x7f) {
        // a single byte whose value is in the [0x00, 0x7f] range, that byte is its own RLP encoding.
        decoded_ = bytes_input;
    } else if(first_byte_ == 0x80) {
        decoded_ = EmptyByte();
    } else if(first_byte_ <= 0xb7) {
        // string is 0-55 bytes long. A single byte with value 0x80 plus the length of the string followed by the string
        // The range of the first byte is [0x80, 0xb7]
        length_ = first_byte_ - 0x7f;
        decoded_ = slice(bytes_input, 1, length_);
    } else if(first_byte_ <= 0xbf) {
        auto l_length_ = first_byte_ - 0xb6;
        const std::vector<uint64_t> part_byte_ = slice(bytes_input, 1, l_length_);
        length_ = SafeParseInt(BytesToString(part_byte_), 16);

        decoded_ = slice(bytes_input, l_length_, length_ + l_length_);
    } else if(first_byte_ <= 0xf7) {
        // a list between 0-55 bytes long
        length_ = first_byte_ - 0xbf;
        auto inner_reminder = slice(bytes_input, 1, length_);
        // while(inner_reminder.size()) {
        //     auto 
        // }
    } else {
        // a list over 55 bytes long
    }

    return decoded_;
}


std::string RLPDecoder::DecodeString(const std::string& input) {
    if(input.empty()) {
        return BytesToString(EmptyByte());
    }

    const std::vector<uint64_t> byte_input_ = ToBytes(input);
    const std::vector<uint64_t> decoded_ = Decode(byte_input_);

    return BytesToString(decoded_);
}