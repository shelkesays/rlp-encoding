#ifndef RLP_RLP_LIST_H
#define RLP_RLP_LIST_H

#include <string>

#include "alias.hpp"

class RLPList {
    private:
        buffer_t _bytes;
        RLPList(buffer_t bytes);
    public:
        buffer_t GetBytes();
        // std::string AsHexString();
        static RLPList Create(const buffer_t input);
        static RLPList Create(const std::string input);
};

#endif
