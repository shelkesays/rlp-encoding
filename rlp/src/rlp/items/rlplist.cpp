#include "rlplist.hpp"

#include <utils/hex.hpp>

rlp::RLPList::RLPList(const buffer_array_t input) {
    _bytes = input;
}

buffer_array_t rlp::RLPList::GetBytes() {
    return _bytes;
}

// std::string rlp::RLPList::AsHexString() {
//     return BytesToString(_bytes);
// }

rlp::RLPList rlp::RLPList::Create(const buffer_array_t input) {
    return RLPList(input);
}

rlp::RLPList rlp::RLPList::Create(const buffer_array_t input) {
    if(input.empty()) {
        // buffer_t empty_byte_ = utils::EmptyByte();
        buffer_array_t empty_byte_;
        empty_byte_.push_back(utils::EmptyByte());
    }


}

rlp::RLPList rlp::RLPList::Create(const variant_t& input) {
    
}   