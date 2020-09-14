#include <gtest/gtest.h>

#include <utils/hex.hpp>

// IntegerToHex Positive Test
TEST(HexTest, IntegerToHex_with_zero) {
    int value_ = 0;
    std::string result_ = verified::utils::IntegerToHex(value_);
    std::string compare_value_ = "00";

    EXPECT_EQ(compare_value_, result_);
}

// IntegerToHex Positive Test
TEST(HexTest, IntegerToHex_with_positive_number) {
    int value_ = 12345;
    std::string result_ = verified::utils::IntegerToHex(value_);
    std::string compare_value_ = "3039";

    EXPECT_EQ(compare_value_, result_);
}

// IntegerToHex Negative Test
TEST(HexTest, IntegerToHex_with_negative_number) {
    int value_ = -123;
    std::string result_ = verified::utils::IntegerToHex(value_);
    std::string compare_value_ = "ff85";

    EXPECT_NE(compare_value_, result_);
}
