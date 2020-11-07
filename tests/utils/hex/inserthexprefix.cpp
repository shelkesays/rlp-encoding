#include <gtest/gtest.h>

#include <utils/hex.hpp>

// InsertHexPrefix Positive Test
TEST(HexTest, InsertHexPrefix_with_0x67) {
  std::string compare_value_ = "0x67";
  std::string value_ = "67";
  std::string result_ = verified::utils::InsertHexPrefix(value_);

  EXPECT_EQ(compare_value_, result_);
}

TEST(HexTest, InsertHexPrefix_with_67) {
  std::string compare_value_ = "67";
  std::string value_ = "67";
  std::string result_ = verified::utils::InsertHexPrefix(value_);

  EXPECT_NE(compare_value_, result_);
}

// InsertHexPrefix Negative Test
TEST(HexTest, InsertHexPrefix_with_different_values) {
  std::string compare_value_ = "0x65";
  std::string value_ = "67";
  std::string result_ = verified::utils::InsertHexPrefix(value_);

  EXPECT_NE(compare_value_, result_);
}
