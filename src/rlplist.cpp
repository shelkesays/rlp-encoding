#include "include/rlplist.hpp"

#include "include/utils.hpp"


RLPList::RLPList(const buffer_t input) {
    _bytes = input;
}

buffer_t RLPList::GetBytes() {
    return _bytes;
}

std::string RLPList::AsHexString() {
    return BytesToString(_bytes);
}

RLPList RLPList::Create(const std::vector <uint64_t> input) {
    return RLPList(input);
}

RLPList RLPList::Create(const std::string input[]) {
    // Todo: Need to change this
    return RLPList(EmptyByte());
}
