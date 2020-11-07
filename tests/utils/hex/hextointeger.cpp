#include <exception>
#include <iostream>

#include <gtest/gtest.h>

#include <utils/hex.hpp>

// HexToInteger Positive Test
TEST(HexTest, HexToInteger_with_empty_string) {
    std::string value_ {""};

    EXPECT_ANY_THROW(verified::utils::HexToInteger(value_));
}

// HexToInteger Positive Test
TEST(HexTest, HexToInteger_with_uninitialized_string) {
    std::string value_;

    EXPECT_ANY_THROW(verified::utils::HexToInteger(value_));
}

// HexToInteger Positive Test
TEST(HexTest, HexToInteger_with_hex_string) {
    std::string value_ {"0x3039"};
    int result_ = verified::utils::HexToInteger(value_);
    int compare_value_ = 12345;

    EXPECT_EQ(compare_value_, result_);
}

// HexToInteger Negative Test
TEST(HexTest, HexToInteger_with_normal_string) {
    std::string value_ {"hi"};
    EXPECT_ANY_THROW(verified::utils::HexToInteger(value_));
}

// Define test with custom exceptions