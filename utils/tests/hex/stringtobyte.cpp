#include <gtest/gtest.h>

#include <utils/hex.hpp>

// StringToByte Empty Positive Test
TEST(HexTest, StringToByte_with_empty_string) {
  buffer_t compare_vect_ {};
  std::string empty_string_ = "";
  buffer_t result_ = verified::utils::StringToBytes(empty_string_);

  EXPECT_EQ(compare_vect_, result_);
}

TEST(HexTest, StringToByte_with_uninitialized_string) {
  buffer_t compare_vect_ {};
  std::string empty_string_;
  buffer_t result_ = verified::utils::StringToBytes(empty_string_);

  EXPECT_EQ(compare_vect_, result_);
}

// StringToByte Empty Negative Test
TEST(HexTest, StringToByte_with_0) {
  buffer_t compare_vect_ {0};
  std::string empty_string_ = "";
  buffer_t result_ = verified::utils::StringToBytes(empty_string_);

  EXPECT_NE(compare_vect_, result_);
}

// StringToByte Value Positive Test
TEST(HexTest, StringToByte_with_same_string) {
  buffer_t compare_vect_ {0x52, 0x61, 0x68, 0x75, 0x6c};
  std::string value_string_ = "Rahul";
  buffer_t result_ = verified::utils::StringToBytes(value_string_);

  EXPECT_EQ(compare_vect_, result_);
}

// StringToByte Value Negative Test
TEST(HexTest, StringToByte_with_different_strings) {
  buffer_t compare_vect_ {0x53, 0x61, 0x68, 0x75, 0x6c};
  std::string value_string_ = "Rahul";
  buffer_t result_ = verified::utils::StringToBytes(value_string_);

  EXPECT_NE(compare_vect_, result_);
}
