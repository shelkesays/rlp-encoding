#include <iostream>

#include <constants/alias.hpp>
// #include <utils/hex.hpp>
// #include <rlp/items/rlpstring.hpp>
// #include <rlp/codec/rlpencode.hpp>
// #include <rlp/codec/rlpdecode.hpp>


int main() {
    std::cout << sizeof(uint_t) << std::endl;
    // std::cout << verified::utils::StringToBytes("Rahul").data() << std::endl;
    // std::cout << std::to_string(0x00) << std::endl;
    // std::string original_str {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
    // std::string original_str {"1✁g"};
    // std::string original_str {"world"};
    // std::vector<uint64_t> encoded_str = rlp::RLPEncoder::EncodeString(original_str);
    // std::cout << "Encoded: " << encoded_str.data() << std::endl;
    // std::cout << rlp::RLPEncoder::GetBytes(encoded_str) << std::endl;

    // std::string byte_str_ = verified::utils::BytesToString(encoded_str);
    // std::string new_str_ = rlp::RLPDecoder::DecodeByte(encoded_str);
    // std::cout << "Decoded: " << new_str_ << std::endl;

    // rlp::RLPString test_ = rlp::RLPString::Create(0L);
    // std::vector<uint64_t> encoded_str_ = rlp::RLPEncoder::EncodeString(test_);
    // std::cout << rlp::RLPEncoder::GetBytes(encoded_str_) << std::endl;
    
    // byte_str_ = verified::utils::BytesToString(encoded_str_);
    // new_str_ = rlp::RLPDecoder::DecodeString(byte_str_);
    // std::cout << "Decoded: " << new_str_ << std::endl;

    return 0;
}
