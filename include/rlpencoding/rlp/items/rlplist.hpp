#ifndef RLP_RLP_LIST_H
#define RLP_RLP_LIST_H

#include <string>

#include <rlpencoding/constants/elementtype.hpp>
#include <rlpencoding/rlp/items/rlpstring.hpp>

namespace verified {
    namespace rlp {
        class RLPList {
            private:
                std::vector<verified::rlp::RLPString> _bytes;
                RLPList(std::vector<verified::rlp::RLPString> bytes);
            public:
                std::vector<verified::rlp::RLPString> GetBytes();
                // std::string AsHexString();
                // static RLPList Create(const buffer_t& input);
                // static RLPList Create(const buffer_array_t& input);
                
                static verified::rlp::RLPString convertToRLPString(const variant_t& input);
                // Individual data types
                static RLPList Create(const std::vector<variant_t>& input);
                static RLPList Create(const std::vector<char>& input);
                static RLPList Create(const std::vector<int>& input);
                static RLPList Create(const std::vector<long>& input);
                static RLPList Create(const std::vector<float>& input);
                static RLPList Create(const std::vector<double>& input);
                static RLPList Create(const buffer_t& input);
                static RLPList Create(const std::vector<uint64_t>& input);
                static RLPList Create(const std::vector<std::string>& input);
        };
    }
}

#endif
