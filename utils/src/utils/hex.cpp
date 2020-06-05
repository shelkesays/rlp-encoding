#include "hex.hpp"

#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include "constants.hpp"
#include "alias.hpp"

buffer_t utils::EmptyByte() {
    return StringToBytes(std::to_string(EMPTY_STRING), true);
}

bool utils::IsNumeric(const std::string& input) {
    return std::all_of(input.begin(), input.end(), ::isdigit);
}

bool utils::IsHexPrefixed(const std::string& input) {
    return input.substr(0, 2) == "0x";
}

std::string utils::InsertHexPrefix(const std::string& input) {
    return "0x" + input;
}

std::string utils::StripHexPrefix(const std::string& input) {
    std::string result_ {input};
    if(IsHexPrefixed(input)) {
        result_ = input.substr(2, input.length());
    }
    return result_;
}

std::string utils::PadToEven(const std::string& input) {
    return (input.length() % 2) ? "0" + input : input;
}

bool utils::IsHexString(const std::string& input) {
    bool flag_ = true;

    std::string stripped_string_ = StripHexPrefix(input);

    flag_ = std::all_of(stripped_string_.begin(), stripped_string_.end(), ::isxdigit);
    
    return flag_;
}

std::string utils::IntegerToHex(const uint64_t input) {
    if (input < 0) {
        // Todo: Throw an error
        return "";
    }

    std::ostringstream stream_;
    stream_ << std::hex << input;

    return PadToEven(stream_.str());
}

uint64_t utils::HexToInteger(const std::string& input) {
    std::string hex_str_ = StripHexPrefix(input);
    uint64_t number = std::stoul(hex_str_, nullptr, 16);
    return number;
}

std::string utils::StringToHex(const std::string& input, bool prefix, bool upper) {
    std::ostringstream stream_;

    unsigned int converter_ {0};

    for (std::string::size_type i = 0; i < input.length(); ++i) {
        converter_ = (unsigned int)(unsigned char)input[i];
        stream_ << std::hex << std::setfill('0') <<
            std::setw(2) << (upper ? std::uppercase : std::nouppercase) << converter_;
    }

    return prefix ? InsertHexPrefix(stream_.str()) : stream_.str();
}

std::string utils::HexToString(const std::string& input) {
    std::string stream_ {""};
    std::string hex_str_ {""};

    std::string::size_type start = IsHexPrefixed(input) ? 2 : 0;
    for(std::string::size_type i = start; i < input.length(); i = i+2) {
        hex_str_ = input.substr(i, 2);
        stream_ += std::stoul(hex_str_, nullptr, 16);
    }
    
    return stream_;
}

std::uint64_t utils::SafeParseInt(const std::string& input, unsigned int base) {
    if (input.substr(0, 2) == "00") {
        // Todo: Throw exception
        return 0;
    }

    return std::stoul(input, 0, base);
}

buffer_t utils::IntegerToBytes(const uint64_t input) {
    buffer_t bytes_;

    std::ostringstream output_;
    // Only positive integers are allowed
    output_ << abs(input);

    std::string converter_str_ = IntegerToHex(std::stoi(output_.str()));
    bytes_.push_back(SafeParseInt(converter_str_, 16));
    return bytes_;
}

uint64_t utils::BytesToInteger(const buffer_t& input) {
    uint64_t result_ {0};
    for(auto item_ : input) {
        result_ = result_ * 10 + item_;
    }
    return result_;
}

buffer_t utils::StringToBytes(const std::string& input, const bool ishex) {
    buffer_t bytes_;
    std::string hex_str_ {""};
    uint64_t hex_char_ {0};
    
    std::string original_string_ {""};
    
    if(!ishex || !IsHexString(input)) {
        original_string_ = StringToHex(input, false);
    } else {
        original_string_ = StripHexPrefix(input);
    }

    for(std::string::size_type i = 0; i < original_string_.length(); i = i + 2) {
        hex_str_ = original_string_.substr(i, 2);
        hex_char_ = std::stoul(hex_str_, nullptr, 16);
        bytes_.push_back(hex_char_);
    }

    return bytes_;
}

std::string utils::BytesToString(const buffer_t& input) {
    std::string byte_str_ {""};
    for(std::string::size_type i = 0; i < input.size(); i++ ) {
        uint64_t byte_ = input[i];
        byte_str_ += byte_;
    }
    return byte_str_;
}

buffer_t utils::ToBytes(const std::string& input) {
    buffer_t bytes_;
    if(input.empty()) {
        // Empty string
        bytes_ = EmptyByte();
    } else if(IsNumeric(input)) {
        // It's a positive number
        auto number_ = SafeParseInt(input);
        bytes_ = IntegerToBytes(number_);
    } else {
        if(IsHexString(input)) {
            bytes_ = StringToBytes(PadToEven(StripHexPrefix(input)), true);
        } else {
            bytes_ = StringToBytes(input);
        }
    }

    return bytes_;
}
