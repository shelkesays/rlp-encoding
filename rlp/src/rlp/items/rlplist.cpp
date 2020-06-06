#include "rlplist.hpp"

#include <utils/hex.hpp>

rlp::RLPList::RLPList(const buffer_t input) {
    _bytes = input;
}

buffer_t rlp::RLPList::GetBytes() {
    return _bytes;
}

// std::string rlp::RLPList::AsHexString() {
//     return BytesToString(_bytes);
// }

rlp::RLPList rlp::RLPList::Create(const std::vector <uint64_t> input) {
    return RLPList(input);
}

rlp::RLPList rlp::RLPList::Create(const std::string input) {
    // Todo: Need to change this
    return RLPList(utils::EmptyByte());
}
