#include <gtest/gtest.h>

#include <rlpencoding/utils/hex.hpp>

// StringToHex Empty Positive Test
TEST(HexTest, StringToHex_with_empty_string) {
  std::string empty_string_ = "";
  EXPECT_ANY_THROW(verified::utils::StringToHex(empty_string_));
}

// StringToHex unitialized Positive Test
TEST(HexTest, StringToHex_with_uninitialized_string) {
  std::string empty_string_;
  EXPECT_ANY_THROW(verified::utils::StringToHex(empty_string_));
}

// StringToHex Positive Test with numbers
TEST(HexTest, StringToHex_with_number_string) {
  std::string empty_string_ = "1234";
  std::string result_ = verified::utils::StringToHex(empty_string_);
  std::string compare_vect_ {"0x31323334"};

  EXPECT_EQ(compare_vect_, result_);
}

// StringToHex Positive Test with floats
TEST(HexTest, StringToHex_with_float_string) {
  std::string empty_string_ = "123.45";
  std::string result_ = verified::utils::StringToHex(empty_string_);
  std::string compare_vect_ {"0x3132332e3435"};

  EXPECT_EQ(compare_vect_, result_);
}

// StringToHex Value Positive Test
TEST(HexTest, StringToHex_with_same_string) {
  std::string value_string_ = "Testing";
  std::string result_ = verified::utils::StringToHex(value_string_);
  std::string compare_vect_ {"0x54657374696e67"};

  EXPECT_EQ(compare_vect_, result_);
}

// StringToHex Value Negative Test
TEST(HexTest, StringToHex_with_different_strings) {
  std::string value_string_ = "Testing";
  std::string result_ = verified::utils::StringToHex(value_string_);
  std::string compare_vect_ {"0x536168756c"};

  EXPECT_NE(compare_vect_, result_);
}
