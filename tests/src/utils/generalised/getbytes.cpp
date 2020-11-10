#include <gtest/gtest.h>

#include <rlpencoding/utils/hex.hpp>

// GetByte Empty Positive Test
TEST(GeneralisedHexTest, GetBytes_with_empty_byte) {
    std::string compare_string_ = "<Bytes>";
    buffer_t empty_vect_ {};
    std::string result_ = verified::utils::GetBytes(empty_vect_);

    EXPECT_EQ(compare_string_, result_);
}

// GetByte Empty Positive Test
TEST(GeneralisedHexTest, GetBytes_with_uninitialized_byte) {
    std::string compare_string_ = "<Bytes>";
    buffer_t empty_vect_;
    std::string result_ = verified::utils::GetBytes(empty_vect_);

    EXPECT_EQ(compare_string_, result_);
}

// GetByte Empty Negative Test
TEST(GeneralisedHexTest, GetBytes_with_empty_string) {
    std::string compare_string_ = "";
    buffer_t empty_vect_ {};
    std::string result_ = verified::utils::GetBytes(empty_vect_);

    EXPECT_NE(compare_string_, result_);
}

// GetByte Empty Negative Test
TEST(GeneralisedHexTest, GetBytes_with_uninitialized_string) {
    std::string compare_string_;
    buffer_t empty_vect_ {};
    std::string result_ = verified::utils::GetBytes(empty_vect_);

    EXPECT_NE(compare_string_, result_);
}

// GetByte Empty Positive Test
TEST(GeneralisedHexTest, GetBytes_with_same_string) {
    std::string compare_string_ = "<Bytes 52 61 68 75 6c>";
    buffer_t value_vect_ {0x52, 0x61, 0x68, 0x75, 0x6c};
    std::string result_ = verified::utils::GetBytes(value_vect_);
    
    EXPECT_EQ(compare_string_, result_);
}

// GetByte Empty Negative Test
TEST(GeneralisedHexTest, GetBytes_with_different_string) {
    std::string compare_string_ = "<Bytes 52 65 68 75 6c>";
    buffer_t value_vect_ {0x52, 0x61, 0x68, 0x75, 0x6c};
    std::string result_ = verified::utils::GetBytes(value_vect_);
    
    EXPECT_NE(compare_string_, result_);
}
