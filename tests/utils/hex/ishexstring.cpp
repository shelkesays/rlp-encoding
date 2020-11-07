#include <gtest/gtest.h>

#include <utils/hex.hpp>

// IsHexString Positive Test
TEST(HexTest, IsHexString_with_empty_string) {
    std::string value_ = "";
    bool result_ = verified::utils::IsHexString(value_);

    EXPECT_TRUE(result_);
}

// IsHexString Positive Test
TEST(HexTest, IsHexString_with_uninitialized_string) {
    std::string value_;
    bool result_ = verified::utils::IsHexString(value_);

    EXPECT_TRUE(result_);
}

// IsHexString Positive Test
TEST(HexTest, IsHexString_with_number_string) {
    std::string value_ {"1234"};
    bool result_ = verified::utils::IsHexString(value_);

    EXPECT_TRUE(result_);
}

// IsHexString Negative Test
TEST(HexTest, IsHexString_with_character_string) {
    std::string value_ {"0xabcg"};
    bool result_ = verified::utils::IsHexString(value_);

    EXPECT_FALSE(result_);
}

// IsHexString Negative Test
TEST(HexTest, IsHexString_with_special_character_string) {
    std::string value_ {"0x@#"};
    bool result_ = verified::utils::IsHexString(value_);

    EXPECT_FALSE(result_);
}

// IsHexString Negative Test
TEST(HexTest, IsHexString_with_numbers_and_character_string) {
    std::string value_ {"0x12aeof"};
    bool result_ = verified::utils::IsHexString(value_);

    EXPECT_FALSE(result_);
}

// IsHexString Negative Test
TEST(HexTest, IsHexString_with_mixed_string) {
    std::string value_ {"0x32ghit@"};
    bool result_ = verified::utils::IsHexString(value_);

    EXPECT_FALSE(result_);
}
