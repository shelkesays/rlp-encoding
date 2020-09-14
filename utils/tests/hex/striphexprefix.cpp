#include <gtest/gtest.h>

#include <utils/hex.hpp>

// StripHexPrefix Positive Test
TEST(HexTest, StripHexPrefix_with_67) {
  std::string compare_value_ = "67";
  std::string value_ = "0x67";
  std::string result_ = verified::utils::StripHexPrefix(value_);

  EXPECT_EQ(compare_value_, result_);
}

// StripHexPrefix Negative Test
TEST(HexTest, StripHexPrefix_with_0x67) {
  std::string compare_value_ = "0x67";
  std::string value_ = "0x67";
  std::string result_ = verified::utils::StripHexPrefix(value_);

  EXPECT_NE(compare_value_, result_);
}

TEST(HexTest, StripHexPrefix_with_different_values) {
  std::string compare_value_ = "66";
  std::string value_ = "0x67";
  std::string result_ = verified::utils::StripHexPrefix(value_);

  EXPECT_NE(compare_value_, result_);
}

TEST(HexTest, StripHexPrefix_passing_decimal_value) {
  std::string compare_value_ = "66";
  std::string value_ = "67";
  std::string result_ = verified::utils::StripHexPrefix(value_);

  EXPECT_NE(compare_value_, result_);
}
