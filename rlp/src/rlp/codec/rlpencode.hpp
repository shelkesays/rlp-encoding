#ifndef RLP_ENCODE_H
#define RLP_ENCODE_H

#include <rlp/items/rlpstring.hpp>

namespace verified {
    namespace rlp {
        class RLPEncoder {
            private:
                /**
                 * @brief Get length of the necoding
                 * 
                 * @param len Length of the string to be encoded
                 * @param offset Offset to be added in the length
                 * @return buffer_t encoded length object
                 */
                static buffer_t EncodeLength(const int len, const int offset);

                /**
                 * @brief Encode the bytes object
                 * 
                 * @param bytes_value Bytes to be encoded
                 * @return buffer_t encoded string
                 */
                static buffer_t Encode(const buffer_t bytes_value);

            public:
                /**
                 * @brief Encode RLPString object
                 * 
                 * @param input RLPString object to be encoded
                 * @return buffer_t Encoded RLPString object
                 */
                static buffer_t EncodeString(RLPString input);

                /**
                 * @brief Encode String object (Normal string/ hex string)
                 * 
                 * @param input String to be encoded in RLP
                 * @return buffer_t Encoded string object
                 */
                static buffer_t EncodeString(const std::string input);

                // static buffer_t EncodeByteList(const buffer_array_t& input);
        };

    }
}

#endif
