#include <iostream>

#include <utils/hex.hpp>
#include <rlp/items/rlpstring.hpp>
#include <rlp/codec/rlpencode.hpp>
#include <rlp/codec/rlpdecode.hpp>


int main() {
    std::cout << utils::StringToBytes("Rahul").data() << std::endl;

    // std::string original_str {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
    std::string original_str {"world"};
    std::vector<uint64_t> encoded_str = RLPEncoder::EncodeString(original_str);
    std::cout << RLPEncoder::GetBytes(encoded_str) << std::endl;

    // std::string byte_str_ = BytesToString(encoded_str);
    std::string new_str_ = RLPDecoder::DecodeByte(encoded_str);
    std::cout << "Decoded: " << new_str_ << std::endl;

    // RLPString test_ = RLPString::Create(0L);
    // std::vector<uint64_t> encoded_str_ = RLPEncoder::EncodeString(test_);
    // std::cout << RLPEncoder::GetBytes(encoded_str_) << std::endl;
    
    // std::string byte_str_ = BytesToString(encoded_str_);
    // new_str_ = RLPDecoder::DecodeString(byte_str_);
    // std::cout << "Decoded: " << new_str_ << std::endl;

    return 0;
}
