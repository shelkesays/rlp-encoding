#include <iostream>

#include <constants/alias.hpp>
#include <utils/hex.hpp>
#include <rlp/items/rlpstring.hpp>
#include <rlp/codec/rlpencode.hpp>
#include <rlp/codec/rlpdecode.hpp>


int main() {

    // std::cout << "Integer: " << std::endl;
    // int number_ = 2147483647;
    // std::string hex_number_ = verified::utils::IntegerToHex(number_);
    // std::cout << "Hexadecimal: " << hex_number_ << std::endl;
    // buffer_t encoded_str_ = verified::rlp::RLPEncoder::EncodeString(hex_number_);
    // std::string byte_str_ = verified::utils::BytesToString(encoded_str_);
    // std::string new_str_ = verified::rlp::RLPDecoder::DecodeByte(encoded_str_);
    // std::cout << "Encoded: " << encoded_str_.data() << std::endl;
    // std::cout << "Bytes: " << verified::utils::GetBytes(encoded_str_) << std::endl;
    // std::cout << "Convert: " << verified::utils::BytesToString(encoded_str_) << std::endl;
    // std::cout << "Decoded byte: " << verified::rlp::RLPDecoder::DecodeByte(encoded_str_) << std::endl;
    // std::cout << "Decoded string: " << verified::rlp::RLPDecoder::DecodeString(byte_str_) << std::endl;
    // std::cout << "Original: " << verified::utils::HexToInteger(new_str_) << std::endl;

    // std::cout << std::endl;

    // verified::rlp::RLPString test_ = verified::rlp::RLPString::Create(number_);
    // encoded_str_ = verified::rlp::RLPEncoder::EncodeString(test_);
    // byte_str_ = verified::utils::BytesToString(encoded_str_);
    // std::cout << "Encoded: " << encoded_str_.data() << std::endl;
    // std::cout << "Bytes: " << verified::utils::GetBytes(encoded_str_) << std::endl;
    // std::cout << "Convert: " << verified::utils::BytesToString(encoded_str_) << std::endl;
    // std::cout << "Decoded byte: " << verified::rlp::RLPDecoder::DecodeByte(encoded_str_) << std::endl;
    // std::cout << "Decoded string: " << verified::rlp::RLPDecoder::DecodeString(byte_str_) << std::endl;
    // std::cout << "Original: " << verified::utils::HexToInteger(new_str_) << std::endl;

    // std::cout << std::endl;
    
    // std::cout << "Float: " << std::endl;
    // double float_number_ = 1.79769e+308;
    // std::string hex_number_ = verified::utils::FloatToHex(float_number_);
    // std::cout << "Hexadecimal: " << hex_number_ << std::endl;
    // buffer_t encoded_str_ = verified::rlp::RLPEncoder::EncodeString(hex_number_);
    // std::string byte_str_ = verified::utils::BytesToString(encoded_str_);
    // std::string new_str_ = verified::rlp::RLPDecoder::DecodeByte(encoded_str_);
    // std::cout << "Encoded: " << encoded_str_.data() << std::endl;
    // std::cout << "Bytes: " << verified::utils::GetBytes(encoded_str_) << std::endl;
    // std::cout << "Convert: " << verified::utils::BytesToString(encoded_str_) << std::endl;
    // std::cout << "Decoded byte: " << verified::rlp::RLPDecoder::DecodeByte(encoded_str_) << std::endl;
    // std::cout << "Decoded string: " << verified::rlp::RLPDecoder::DecodeString(byte_str_) << std::endl;
    // std::cout << "Original: " << verified::utils::HexToFloat(new_str_) << std::endl;

    // std::cout << std::endl;

    // verified::rlp::RLPString test_ = verified::rlp::RLPString::Create(float_number_);
    // encoded_str_ = verified::rlp::RLPEncoder::EncodeString(test_);
    // byte_str_ = verified::utils::BytesToString(encoded_str_);
    // new_str_ = verified::rlp::RLPDecoder::DecodeByte(encoded_str_);
    // std::cout << "Encoded: " << encoded_str_.data() << std::endl;
    // std::cout << "Bytes: " << verified::utils::GetBytes(encoded_str_) << std::endl;
    // std::cout << "Convert: " << verified::utils::BytesToString(encoded_str_) << std::endl;
    // std::cout << "Decoded byte: " << verified::rlp::RLPDecoder::DecodeByte(encoded_str_) << std::endl;
    // std::cout << "Decoded string: " << verified::rlp::RLPDecoder::DecodeString(byte_str_) << std::endl;
    // std::cout << "Original: " << verified::utils::HexToFloat(new_str_) << std::endl;

    // std::cout << std::endl;

    std::cout << "String: " << std::endl;
    std::string original_str_ {"Hello there, I am a very very long string, and I am going get encoded in RLP!"};
    // std::string original_str_ {"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"};
    // std::string original_str_ {"1✁g"};
    // std::string original_str_ {"{key: Hello World!, key: value}"};
    buffer_t encoded_str_ = verified::rlp::RLPEncoder::EncodeString(original_str_);
    std::string byte_str_ = verified::utils::BytesToString(encoded_str_);
    std::cout << "Encoded: " << encoded_str_.data() << std::endl;
    std::cout << "Bytes: " << verified::utils::GetBytes(encoded_str_) << std::endl;
    std::cout << "Convert: " << verified::utils::BytesToString(encoded_str_) << std::endl;
    std::cout << "Decoded byte: " << verified::rlp::RLPDecoder::DecodeByte(encoded_str_) << std::endl;
    std::cout << "Decoded string: " << verified::rlp::RLPDecoder::DecodeString(byte_str_) << std::endl;

    std::cout << std::endl;
    
    verified::rlp::RLPString test_ = verified::rlp::RLPString::Create(original_str_);
    encoded_str_ = verified::rlp::RLPEncoder::EncodeString(original_str_);
    byte_str_ = verified::utils::BytesToString(encoded_str_);
    std::cout << "Encoded: " << encoded_str_.data() << std::endl;
    std::cout << "Bytes: " << verified::utils::GetBytes(encoded_str_) << std::endl;
    std::cout << "Convert: " << verified::utils::BytesToString(encoded_str_) << std::endl;
    std::cout << "Decoded byte: " << verified::rlp::RLPDecoder::DecodeByte(encoded_str_) << std::endl;
    std::cout << "Decoded string: " << verified::rlp::RLPDecoder::DecodeString(byte_str_) << std::endl;

    // std::cout << std::endl;
    // std::cout << "Empty: " << std::endl;
    // verified::rlp::RLPString test_ = verified::rlp::RLPString::Create(0L);
    // encoded_str_ = verified::rlp::RLPEncoder::EncodeString(test_);
    // byte_str_ = verified::utils::BytesToString(encoded_str_);
    // std::cout << "Encoded: " << encoded_str_.data() << std::endl;
    // std::cout << "Bytes: " << verified::rlp::RLPEncoder::GetBytes(encoded_str_) << std::endl;
    // std::cout << "Convert: " << verified::utils::BytesToString(encoded_str_) << std::endl;
    // std::cout << "Decoded byte: " << verified::rlp::RLPDecoder::DecodeByte(encoded_str_) << std::endl;
    // std::cout << "Decoded string: " << verified::rlp::RLPDecoder::DecodeString(byte_str_) << std::endl;

    return 0;
}
