#include <gtest/gtest.h>

#include <rlpencoding/utils/hex.hpp>

// HexToFloat Positive Test
TEST(HexTest, HexToFloat_with_empty_string) {
    std::string value_ {""};

    EXPECT_ANY_THROW(verified::utils::HexToFloat(value_));
}

// HexToFloat Positive Test
TEST(HexTest, HexToFloat_with_uninitialized_string) {
    std::string value_;

    EXPECT_ANY_THROW(verified::utils::HexToFloat(value_));
}

// HexToFloat Positive Test
TEST(HexTest, HexToFloat_with_hex_string) {
    std::string value_ {"0x1.edccccp+6"};
    float result_ = verified::utils::HexToFloat(value_);
    float compare_value_ = 123.45;

    EXPECT_EQ(compare_value_, result_);
}

// HexToFloat Negative Test
TEST(HexTest, HexToFloat_with_normal_string) {
    std::string value_ {"hi"};
    EXPECT_ANY_THROW(verified::utils::HexToFloat(value_));
}

// Define test with custom exceptions