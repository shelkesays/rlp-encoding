#ifndef UTILS_GENERALISED_H
#define UTILS_GENERALISED_H

#include <rlpencoding/constants/alias.hpp>
#include <rlpencoding/constants/macros.hpp>
#include <rlpencoding/constants/elementtype.hpp>

template<typename T>
std::string ToString(const T& input) {
    std::ostringstream stream_;
    stream_ << input;
    return stream_.str();
}

template<typename T>
bool IsNonValue(T input) {
    bool status_ = (input == NULL);

    if(!status_) {
        switch (input.which()) {
            case ElementType::INT:
            case ElementType::LONG:
            case ElementType::UINT:
            case ElementType::UNINT64:
                status_ = (input <= 0);
                break;

            case ElementType::STRING:
            case ElementType::BUFFER:
            case ElementType::BUFFER_ARRAY:
                status_ = input.empty();
                break;
        
            default:
                // Todo check if it is an array / pointer
                break;
        }
    }
    
    return status_;
}

template<typename T>
std::vector<T> Slice(const std::vector<T>& vect, int start, int end) {
    if(end == -1) {
       end = vect.size() - 1;
    }

    auto first_ = vect.begin() + start;
    auto last_ = vect.begin() + end + 1;
    std::vector<T> sliced_vector_(first_, last_);

    return sliced_vector_;
}

template<typename T>
int GetLength(const T& input) {
    if (!input || input.size() == 0) {
        return EMPTY_STRING;
    }

    const buffer_t input_byte_ = ToBytes(input);
    const auto first_byte_ = input_byte_[0];

    int result = 0;

    if(first_byte_ <= SHORT_STRING) {
        result = input_byte_.size();
    } else if(first_byte_ <= LONG_STRING) {
        result = first_byte_ - SHORT_STRING;
    } else if(first_byte_ <= SHORT_LIST) {
        result = first_byte_ - 0xb6;
    } else if(first_byte_ <= 0xf7) {
        // a list between 0-55 bytes long
        result = first_byte_ - SHORT_LIST;
    } else {
        // a list over 55 bytes long
        const uint64_t l_length_ = first_byte_ - LONG_LIST;

        buffer_t part_byte_ = Slice(input_byte_, 1, l_length_);

        std::string part_string_ = BytesToString(part_byte_);
    
        const uint64_t length = SafeParseInt(part_string_, 16); 

        result = l_length_ + length;
    }

    return result;
}

template<typename Base, typename T>
inline bool instanceof(const T*) {
   return std::is_base_of<Base, T>::value;
}

template <typename T>
std::string GetBytes(T input) {
    std::string byte_str_ {"<Bytes"};
    for(std::size_t i = 0; i < input.size(); i++ ) {
        uint64_t byte_ = input[i];
        byte_str_ += " " + IntegerToHex(byte_);
    }

    return byte_str_ + ">";
}

#endif
