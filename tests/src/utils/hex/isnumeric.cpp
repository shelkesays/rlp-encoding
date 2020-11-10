#include <gtest/gtest.h>

// #include <utils/hex.hpp>
#include <rlpencoding/utils/hex.hpp>

// IsNumeric Positive Test
TEST(HexTest, IsNumeric_with_1234_string) {
  std::string value_ = "1234";
  bool result_ = verified::utils::IsNumeric(value_);

  EXPECT_TRUE(result_);
}

// IsNumeric Negative Test
TEST(HexTest, IsNumeric_with_abcd_string) {
  std::string value_ = "abcd";
  bool result_ = verified::utils::IsNumeric(value_);

  EXPECT_FALSE(result_);
}

// IsNumeric Negative Test
TEST(HexTest, IsNumeric_with_empty_string) {
  std::string value_ = "";
  bool result_ = verified::utils::IsNumeric(value_);

  EXPECT_FALSE(result_);
}

TEST(HexTest, IsNumeric_with_uninitialized_string) {
  std::string value_;
  bool result_ = verified::utils::IsNumeric(value_);

  EXPECT_FALSE(result_);
}
