#include <iostream>
#include <vector>
#include <stdint.h>

#include "inc/utils.hpp"
#include "inc/rlpstring.hpp"
#include "inc/rlpencode.hpp"

int main() {
    std::string original_str {"Hello World! This is another test tp check the strenght the programs."};
    
    // std::vector<char> bytes_str = ConvertToBytes(original_str);
    // std::cout << bytes_str.data() << std::endl;

    // bytes_str.insert(bytes_str.begin(), bytes_str.size() + 0x80);
    // std::cout << bytes_str.data() << std::endl;

    // std::string hex = StringToHex(bytes_str.data());
    // std::cout << hex.length() << std::endl;
    // std::string str = HexToString(hex);

    // std::cout << "Original String: " << original_str << std::endl;
    // std::cout << "Hex String: " << hex << std::endl;
    // std::cout << "Converted String: " << str << std::endl;

    // std::vector<char> bytes_str { 1, 2, 3, 4, 5 };
    // uint64_t number = 10928774;
    // std::cout << IntegerToBytes(number) << std::endl;
    // std::cout << abs(bytes_str[0]) << std::endl;
    // std::cout << ConvertToInteger(bytes_str) << std::endl;

    RLPString test_ = RLPString::Create(original_str);
    // std::vector<char> bytes_str = test_.GetBytes();
    // std::cout << bytes_str.data() << std::endl;
    // std::cout << test_.AsHexString() << std::endl;

    std::vector<char> encoded_str = RLPEncoder::EncodeString(original_str);
    std::cout << encoded_str.data() << std::endl;

    std::vector<char> encoded_str_ = RLPEncoder::EncodeString(test_);
    std::cout << encoded_str_.data() << std::endl;

    int t1 = 54;
    wchar_t t2 = 0x80;
    auto te = typeid(t1) == typeid(int);
    std::cout << te << std::endl;
    std::cout << typeid(t2).name() << std::endl;
    std::cout << typeid(original_str).name() << std::endl;
    return 0;
}
