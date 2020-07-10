#ifndef RLP_RLP_STRING_H
#define RLP_RLP_STRING_H

#include <string>

#include <constants/alias.hpp>

namespace verified {
    namespace rlp {
        class RLPString {
            private:
                buffer_t _bytes;

                /**
                 * @brief Construct a new RLPString object
                 * 
                 * @param bytes Bytes to be converted to RLPString object
                 */
                RLPString(const buffer_t bytes);

            public:
                
                /**
                 * @brief Get the Bytes object
                 * 
                 * @return buffer_t RLPString bytes
                 */
                buffer_t GetBytes();

                /**
                 * @brief Get Hex representation of the RLPString object
                 * 
                 * @return std::string String representation of the RLPString
                 */
                std::string AsHexString();
                
                /**
                 * @brief Create RLPString from character
                 * 
                 * @param input character to be represented as RLPString
                 * @return RLPString object of the input character
                 */
                static RLPString Create(const char input);

                /**
                 * @brief Create RLPString from integer number
                 * 
                 * @param input integer number to be represented as RLPString
                 * @return RLPString object of the input integer number
                 */
                static RLPString Create(const int input);

                /**
                 * @brief Create RLPString from long number
                 * 
                 * @param input long number to be represented as RLPString
                 * @return RLPString object of the input long number
                 */
                static RLPString Create(const long input);

                /**
                 * @brief Create RLPString from unsigned integer number
                 * 
                 * @param input unsigned integer number to be represented as RLPString
                 * @return RLPString object of the input unsigned integer number
                 */
                static RLPString Create(const uint_t input);

                /**
                 * @brief Create RLPString from 64 bit unsigned integer number
                 * 
                 * @param input 64 bit unsingned integer number to be represented as RLPString
                 * @return RLPString object of the input 64 bit undigned integer number
                 */
                static RLPString Create(const uint64_t input);

                /**
                 * @brief Create RLPString from a float number
                 * 
                 * @param input float number to be represented as RLPString
                 * @return RLPString object of the input float number
                 */
                static RLPString Create(const float input);

                /**
                 * @brief Create RLPString from a double number
                 * 
                 * @param input double number to be represented as RLPString
                 * @return RLPString object of the input double number
                 */
                static RLPString Create(const double input);

                /**
                 * @brief Create RLPString from buffer value (vector/array of undigned integer numbers)
                 * 
                 * @param input buffer value to be represented as RLPString
                 * @return RLPString object of the input buffer
                 */
                static RLPString Create(const buffer_t input);

                /**
                 * @brief Create RLPString from string value
                 * 
                 * @param input String value to be represented as RLPString
                 * @return RLPString object of the input string value
                 */
                static RLPString Create(const std::string input);
        };
    }
}

#endif
