#include <rlpencoding/rlp/items/rlplist.hpp>

#include <rlpencoding/utils/hex.hpp>

verified::rlp::RLPList::RLPList(const std::vector<verified::rlp::RLPString> input) {
    _bytes = input;
}

std::vector<verified::rlp::RLPString> verified::rlp::RLPList::GetBytes() {
    return _bytes;
}

// std::string verified::rlp::RLPList::AsHexString() {
//     return BytesToString(_bytes);
// }

verified::rlp::RLPString verified::rlp::RLPList::convertToRLPString(const variant_t& input) {
    verified::rlp::RLPString bytes_;
    switch (input.which()) {
        case ElementType::CHAR: {
            auto inpt_ = boost::get<char>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        case ElementType::INT: {
            auto inpt_ = boost::get<int>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        case ElementType::LONG: {
            auto inpt_ = boost::get<long>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        case ElementType::FLOAT: {
            auto inpt_ = boost::get<float>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        case ElementType::DOUBLE: {
            auto inpt_ = boost::get<double>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        case ElementType::UINT: {
            auto inpt_ = boost::get<uint_t>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        case ElementType::UNINT64: {
            auto inpt_ = boost::get<uint64_t>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        case ElementType::STRING: {
            auto inpt_ = boost::get<std::string>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        case ElementType::BUFFER: {
            auto inpt_ = boost::get<buffer_t>(input);
            bytes_ = verified::rlp::RLPString::Create(inpt_);
            break;
            }
        // case ElementType::BUFFER_ARRAY: {
        //     auto inpt_ = boost::get<buffer_array_t>(input);
        //     bytes_ = verified::rlp::RLPString::Create(inpt_);
        //     break;
        //     }
        default:
            // TODO add error
            break;
        }

        return bytes_;
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const std::vector<variant_t>& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString bytes_;
    for (size_t i = 0; i < input.size(); i++) {
        bytes_ = convertToRLPString(input.at(i));
        bytes_list_.push_back(bytes_);
    }
    return RLPList(bytes_list_);
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const std::vector<char>& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString item;
    for (size_t i = 0; i < input.size(); i++) {
        item = verified::rlp::RLPString::Create(input.at(i));
        bytes_list_.push_back(item);
    }
    return RLPList(bytes_list_);
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const std::vector<int>& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString item;
    for (size_t i = 0; i < input.size(); i++) {
        item = verified::rlp::RLPString::Create(input.at(i));
        bytes_list_.push_back(item);
    }
    return RLPList(bytes_list_);
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const std::vector<long>& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString item;
    for (size_t i = 0; i < input.size(); i++) {
        item = verified::rlp::RLPString::Create(input.at(i));
        bytes_list_.push_back(item);
    }
    return RLPList(bytes_list_);
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const std::vector<float>& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString item;
    for (size_t i = 0; i < input.size(); i++) {
        item = verified::rlp::RLPString::Create(input.at(i));
        bytes_list_.push_back(item);
    }
    return RLPList(bytes_list_);
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const std::vector<double>& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString item;
    for (size_t i = 0; i < input.size(); i++) {
        item = verified::rlp::RLPString::Create(input.at(i));
        bytes_list_.push_back(item);
    }
    return RLPList(bytes_list_);
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const buffer_t& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString item;
    for (size_t i = 0; i < input.size(); i++) {
        item = verified::rlp::RLPString::Create(input.at(i));
        bytes_list_.push_back(item);
    }
    return RLPList(bytes_list_);
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const std::vector<uint64_t>& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString item;
    for (size_t i = 0; i < input.size(); i++) {
        item = verified::rlp::RLPString::Create(input.at(i));
        bytes_list_.push_back(item);
    }
    return RLPList(bytes_list_);
}

verified::rlp::RLPList verified::rlp::RLPList::Create(const std::vector<std::string>& input) {
    std::vector<verified::rlp::RLPString> bytes_list_;
    verified::rlp::RLPString item;
    for (size_t i = 0; i < input.size(); i++) {
        item = verified::rlp::RLPString::Create(input.at(i));
        bytes_list_.push_back(item);
    }
    return RLPList(bytes_list_);
}
