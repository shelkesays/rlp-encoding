#include <gtest/gtest.h>

#include <utils/hex.hpp>

// StringToByte Empty Positive Test
TEST(HexTest, StringToByte_with_empty_string) {
  std::string empty_string_ = "";
  EXPECT_ANY_THROW(verified::utils::StringToBytes(empty_string_));
}

TEST(HexTest, StringToByte_with_uninitialized_string) {
  std::string empty_string_;
  EXPECT_ANY_THROW(verified::utils::StringToBytes(empty_string_));
}

// StringToByte Empty Negative Test
TEST(HexTest, StringToByte_with_0) {
  std::string zero_string_ = "0";
  buffer_t result_ = verified::utils::StringToBytes(zero_string_);
  buffer_t compare_vect_ {0};

  EXPECT_NE(compare_vect_, result_);
}

// StringToByte Value Positive Test
TEST(HexTest, StringToByte_with_same_string) {
  std::string value_string_ = "Test";
  buffer_t result_ = verified::utils::StringToBytes(value_string_);
  buffer_t compare_vect_ { 84, 101, 115, 116 };

  EXPECT_EQ(compare_vect_, result_);
}

// StringToByte Value Negative Test
TEST(HexTest, StringToByte_with_different_strings) {
  std::string value_string_ = "Test";
  buffer_t result_ = verified::utils::StringToBytes(value_string_);
  buffer_t compare_vect_ {0x53, 0x61, 0x68, 0x75, 0x6c};

  EXPECT_NE(compare_vect_, result_);
}
