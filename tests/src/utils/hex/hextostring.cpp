#include <exception>
#include <iostream>

#include <gtest/gtest.h>

#include <rlpencoding/utils/hex.hpp>

// HexToString Positive Test
TEST(HexTest, HexToString_with_empty_string) {
    std::string value_ {""};
    std::string result_ = verified::utils::HexToString(value_);
    std::string compare_value_ {""};
    EXPECT_EQ(compare_value_, result_);
}

// HexToString Positive Test
TEST(HexTest, HexToString_with_uninitialized_string) {
    std::string value_;
    std::string result_ = verified::utils::HexToString(value_);
    std::string compare_value_ {""};
    EXPECT_EQ(compare_value_, verified::utils::HexToString(value_));
}

// HexToString Positive Test
TEST(HexTest, HexToString_with_hex_string) {
    std::string value_ {"0x4869"};
    std::string result_ = verified::utils::HexToString(value_);
    std::string compare_value_ = "Hi";
    EXPECT_EQ(compare_value_, result_);
}

// HexToString Negative Test
TEST(HexTest, HexToString_with_normal_string) {
    std::string value_ {"hi"};
    EXPECT_ANY_THROW(verified::utils::HexToString(value_));
}

// Define test with custom exceptions