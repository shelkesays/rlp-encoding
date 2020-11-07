#include <gtest/gtest.h>

#include <utils/hex.hpp>

// IsHexPrefixed Positive Test
TEST(HexTest, IsHexPrefixed_with_0x1234) {
  std::string value_ = "0x1234";
  bool result_ = verified::utils::IsHexPrefixed(value_);

  EXPECT_TRUE(result_);
}

// IsHexPrefixed Negative Test
TEST(HexTest, IsHexPrefixed_with_1234) {
  std::string value_ = "1234";
  bool result_ = verified::utils::IsHexPrefixed(value_);

  EXPECT_FALSE(result_);
}
