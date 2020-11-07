#include <gtest/gtest.h>

#include <utils/hex.hpp>

// PadToEven Positive Test
TEST(HexTest, PadToEven_with_empty_string) {
    std::string value_ = "";
    std::string result_ = verified::utils::PadToEven(value_);
    std::string compare_value_ = "";

    EXPECT_EQ(compare_value_, result_);
}

// PadToEven Positive Test
TEST(HexTest, PadToEven_with_uninitialized_string) {
    std::string value_;
    std::string result_ = verified::utils::PadToEven(value_);
    std::string compare_value_ = "";

    EXPECT_EQ(compare_value_, result_);
}

// PadToEven Positive Test
TEST(HexTest, PadToEven_with_even_digits_string) {
    std::string value_ {"1234"};
    std::string result_ = verified::utils::PadToEven(value_);
    std::string compare_value_ = "1234";

    EXPECT_EQ(compare_value_, result_);
}

// PadToEven Negative Test
TEST(HexTest, PadToEven_with_odd_digits_string) {
    std::string value_ {"12345"};
    std::string result_ = verified::utils::PadToEven(value_);
    std::string compare_value_ = "1234";

    EXPECT_NE(compare_value_, result_);
}

// PadToEven Negative Test
TEST(HexTest, PadToEven_with_even_characters_string) {
    std::string value_ {"abcd"};
    std::string result_ = verified::utils::PadToEven(value_);
    std::string compare_value_ = "0abcd";

    EXPECT_NE(compare_value_, result_);
}

// PadToEven Positive Test
TEST(HexTest, PadToEven_with_odd_characters_string) {
    std::string value_ {"pqr"};
    std::string result_ = verified::utils::PadToEven(value_);
    std::string compare_value_ = "0pqr";
    
    EXPECT_EQ(compare_value_, result_);
}
