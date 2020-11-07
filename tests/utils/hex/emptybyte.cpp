#include <gtest/gtest.h>

#include <utils/hex.hpp>

// EmptyByte positive test
TEST(HexTest, EmptyByte_with_empty_value) {
  buffer_t compare_vect_ {0};
  buffer_t result_ = verified::utils::EmptyByte();

  EXPECT_EQ(compare_vect_, result_);
}

// EmptyByte Negative Test
TEST(HexTest, EmptyByte_with_1) {
  buffer_t compare_vect_ {0x61};
  buffer_t result_ = verified::utils::EmptyByte();

  EXPECT_NE(compare_vect_, result_);
}
