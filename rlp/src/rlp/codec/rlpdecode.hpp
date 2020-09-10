#ifndef RLP_DECODE_H
#define RLP_DECODE_H

#include <string>

#include <constants/alias.hpp>

namespace verified {
    namespace rlp {
        class RLPDecoder {
            private:
                /**
                 * @brief Decode the bytes object encoded using RLP
                 * 
                 * @param bytes_input Bytes object to be decoded
                 * @return buffer_t decoded object
                 */
                static buffer_t Decode(const buffer_t& bytes_input);
            public:
                /**
                 * @brief Decode the byte object, encoded using RLP
                 * 
                 * @param input Byte object to be decoded
                 * @return std::string Decoded string
                 */
                static std::string DecodeByte(const buffer_t& input);

                /**
                 * @brief Decode the string encoded using RLP
                 * 
                 * @param input string to be decoded
                 * @return std::string Decoded string
                 */
                static std::string DecodeString(const std::string& input);

                // static buffer_array_t DecodeByteList(const buffer_t &input);
        };
    }
}

#endif