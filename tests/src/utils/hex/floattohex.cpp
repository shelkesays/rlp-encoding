#include <gtest/gtest.h>

#include <rlpencoding/utils/hex.hpp>

// FloatToHe Negative test
TEST(HexTest, FloatToHex_with_zero) {
    float value_ = 0.0;
    std::string result_ = verified::utils::FloatToHex(value_);
    std::string compare_value_ = "0.0";

    EXPECT_NE(compare_value_, result_);
}

// FloatToHex Positive Test
TEST(HexTest, FloatToHex_with_positive_number) {
    float value_ = 123.45;
    std::string result_ = verified::utils::FloatToHex(value_);
    std::string compare_value_ = "00x1.edccccp+6";

    EXPECT_EQ(compare_value_, result_);
}

// IntegerToHex Positive Test
TEST(HexTest, FloatToHex_with_negative_number) {
    int value_ = -123.00;

    EXPECT_ANY_THROW(verified::utils::FloatToHex(value_));
}
