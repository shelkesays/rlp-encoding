#include "inc/utils.hpp"
#include "inc/rlpstring.hpp"
#include "inc/rlpencode.hpp"
#include "inc/rlpdecode.hpp"

int main() {
    // uint64_t number_ = 0x48;
    // std::cout << "HEX: " << std::hex << number_ << std::endl;
    // std::cout << "INTEGER HEX: " << IntegerToHex(number_) << std::endl;
    // std::cout << "HEX STRING: " << HexToString(IntegerToHex(number_)) << std::endl;
    // std::cout << "STRING HEX: " << StringToHex("a") << std::endl;
    std::string original_str {"Hello"}; //{"Hello World! This is another test tp check the strenght the programs."};
    // auto str_hex_ = StringToHex(original_str);
    // auto hex_str_ = HexToString(str_hex_);
    // std::cout << "ORIGINAL: " << str_hex_ << std::endl;
    // std::cout << "ORIGINAL: " << hex_str_ << std::endl;

    RLPString test_ = RLPString::Create(original_str);
    std::vector<uint64_t> bytes_str = test_.GetBytes();
    // std::cout << "Get Bytes: " << bytes_str.data() << std::endl;
    // std::cout << "AS HEx: " << test_.AsHexString() << std::endl;

    std::vector<uint64_t> encoded_str = RLPEncoder::EncodeString(original_str);
    std::cout << "String: " << encoded_str.data() << std::endl;

    std::vector<uint64_t> encoded_str_ = RLPEncoder::EncodeString(test_);
    std::cout << "RLP String: " << encoded_str_.data() << std::endl;

    std::string byte_str_ = BytesToString(encoded_str_);
    std::cout << "Byte String: " << byte_str_ << std::endl;
    std::string new_str_ = RLPDecoder::DecodeString(byte_str_);
    std::cout << new_str_ << std::endl;
    // int t1 = 54;
    // wchar_t t2 = std::stoi("0x7f", 0, 16);
    // std::cout << "7F: " << t2 << std::endl;
    // int t2 = 127;
    // auto te = typeid(t1) == typeid(int);
    // std::cout << std::hex << t2 << std::endl;
    // std::cout << typeid(t2).name() << std::endl;
    // std::cout << typeid(original_str).name() << std::endl;

    // int num = 30;
    // std::string str = IntegerToHex(num);
    // std::cout << "HEX: " << str << std::endl;
    // // wchar_t t1 = std::stoi("0x1e", 0, 16);
    // // std::cout << t1 << std::endl;
    // wchar_t test = SafeParseInt(str, 16);
    // std::cout << test << std::endl;

    // std::string s = "0xBF0x540x320xFE0x880x100x340x6F0x54";
    // auto sub_str = SafeParseInt("BF", 16);
    // std::cout << s.substr(0, 4) << std::endl;
    // std::cout << std::hex << sub_str << std::endl;

    // std::string hex = StripHexPrefix(StringToHex(original_str));
    // std::cout << hex << std::endl;
    // uint64_t sub_cat {0};
    // for(std::string::size_type i = 0; i < hex.size(); i = i+2) {
    //     sub_cat = SafeParseInt(hex.substr(i, 2), 16);
    //     std::cout << hex.substr(i, 2)  << ": " << sub_cat << ": " << HexToString(std::to_string(sub_cat)) << std::endl;
    // }
    return 0;
}
