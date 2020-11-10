#include <rlpencoding/utils/hex.hpp>

#include <iostream>
#include <iomanip>
#include <algorithm>

#include <rlpencoding/constants/macros.hpp>

buffer_t verified::utils::EmptyByte() {
    return StringToBytes(std::to_string(EMPTY_STRING), true);
}

bool verified::utils::IsNumeric(const std::string& input) {
    bool status_ = true;
    if(!input.empty()) {
        status_ = std::all_of(input.begin(), input.end(), [](unsigned char c){ return std::isdigit(c); });
    } else {
        // it is empty string or not initialized
        status_  = false;
    }

    return status_;
}

bool verified::utils::IsHexPrefixed(const std::string& input) {
    return input.substr(0, 2) == "0x";
}

std::string verified::utils::InsertHexPrefix(const std::string& input) {
    return "0x" + input;
}

std::string verified::utils::StripHexPrefix(const std::string& input) {
    return IsHexPrefixed(input) ? input.substr(2, input.length()) : input;
}

std::string verified::utils::PadToEven(const std::string& input) {
    return (input.length() % 2) ? "0" + input : input;
}

bool verified::utils::IsHexString(const std::string& input) {
    std::string stripped_string_ = StripHexPrefix(input);
    return std::all_of(stripped_string_.begin(), stripped_string_.end(),  [](unsigned char c){ return std::isxdigit(c); });
}

std::string verified::utils::IntegerToHex(const uint64_t input) {
    // if (input < 0) {
    //     // @Todo: Throw an custom exception, rather than the message
    //     return "Only positive integers are allowed";
    // }

    std::ostringstream stream_;
    stream_ << std::hex << input;

    return PadToEven(stream_.str());
}

uint64_t verified::utils::HexToInteger(const std::string& input) {
    if(input.empty() || !IsHexString(input)) {
        // Todo: Throw custom exception, rather than the message
        throw "Not a hex string, please check the value.";
    }
    std::string hex_str_ = StripHexPrefix(input);
    uint64_t number_ = std::stoul(hex_str_, nullptr, 16);
    return number_;
}

std::string verified::utils::FloatToHex(const double input) {
    if (input < 0.0) {
        // Todo: Throw a custom error
        throw "Only positive numbers are allowed";
    }

    std::ostringstream stream_;
    stream_ << std::hexfloat << input;

    return PadToEven(stream_.str());
}

double verified::utils::HexToFloat(const std::string& input) {
    if(input.empty()) {
        // Todo: Throw custom exception, rather than the message
        throw "Not a hex string, please check the value.";
    }
    std::ostringstream stream_;
    stream_ << std::defaultfloat << input;

    return std::stod(stream_.str());
}

std::string verified::utils::StringToHex(const std::string& input, bool prefix, bool upper) {
    if(input.empty()) {
        // Todo: Throw custom exception, rather than the message
        throw "Empty or uninitialized string is not allowed.";
    }

    std::ostringstream stream_;

    unsigned int converter_ {0};

    for (std::size_t i = 0; i < input.length(); ++i) {
        converter_ = (unsigned int)(unsigned char)input[i];
        stream_ << std::hex << std::setfill('0') <<
            std::setw(2) << (upper ? std::uppercase : std::nouppercase) << converter_;
    }

    return prefix ? InsertHexPrefix(stream_.str()) : stream_.str();
}

std::string verified::utils::HexToString(const std::string& input) {
    std::string stream_ {""};
    std::string hex_str_ {""};

    const std::size_t start_ = IsHexPrefixed(input) ? 2 : 0;
    for(std::size_t i = start_; i < input.length(); i = i + 2) {
        hex_str_ = input.substr(i, 2);
        stream_ += std::to_string(std::stoul(hex_str_, nullptr, 16));
    }
    
    return stream_;
}

uint_t verified::utils::SafeParseInt(const std::string& input, unsigned int base) {
    if (input.substr(0, 2) == "00") {
        // Todo: Throw exception
        return 0;
    }

    return (uint_t) std::stoul(input, 0, base);
}

buffer_t verified::utils::IntegerToBytes(const uint64_t input) {
    // Only positive integers are allowed
    // uint64_t output_ = ((input >= 0) ? input : (-1 * input));
    // @Todo: Remove line 136 and enable line 134
    uint64_t output_ = input;

    std::string converter_str_ = IntegerToHex(output_);

    buffer_t bytes_;
    bytes_.push_back(SafeParseInt(converter_str_, 16));
    return bytes_;
}

uint64_t verified::utils::BytesToInteger(const buffer_t& input) {
    uint64_t result_ {0};
    for(auto item_ : input) {
        result_ = result_ * 10 + item_;
    }
    return result_;
}

buffer_t verified::utils::FloatToBytes(const double input) {
    // Only positive numbers are allowed
    double output_ = ((input >= 0) ? input : (-1 * input));

    std::string converter_str_ = FloatToHex(output_);

    return StringToBytes(converter_str_, true);
}

double verified::utils::BytesToFloat(const buffer_t& input) {
    std::string hex_str_ = BytesToString(input);
    return HexToFloat(hex_str_);
}

buffer_t verified::utils::StringToBytes(const std::string& input, const bool ishex) {
    if(input.empty()) {
        // Todo: Throw custom exception, rather than the message
        throw "Empty or uninitialized string is not allowed.";
    }

    buffer_t bytes_;
    std::string hex_str_ {""};
    uint_t hex_char_ {0};
    
    std::string original_string_ = (!ishex || !IsHexString(input)) ? StringToHex(input, false) : StripHexPrefix(input);

    for(std::size_t i = 0; i < original_string_.length(); i = i + 2) {
        hex_str_ = original_string_.substr(i, 2);
        hex_char_ = std::stoul(hex_str_, nullptr, 16);
        bytes_.push_back(hex_char_);
    }

    return bytes_;
}

std::string verified::utils::BytesToString(const buffer_t& input) {
    std::string byte_str_ {""};
    for(std::size_t i = 0; i < input.size(); i++ ) {
        uint64_t byte_ = input[i];
        byte_str_ += byte_;
    }
    return byte_str_;
}

buffer_t verified::utils::ToBytes(const std::string& input) {
    buffer_t bytes_;

    if(input.empty()) {
        // Empty string
        bytes_ = EmptyByte();
    } else if(IsNumeric(input)) {
        // It's a positive number
        auto number_ = SafeParseInt(input);
        bytes_ = IntegerToBytes(number_);
    } else {
            // If the input is of length 1 and it is between a-f, consider it as non hex
            bool flag_ = !(input.length() == 1 && IsHexString(input));
            bytes_ = StringToBytes(input, flag_);
    }

    return bytes_;
}
