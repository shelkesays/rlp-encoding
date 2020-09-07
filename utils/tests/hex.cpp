#include <gtest/gtest.h>

#include <utils/hex.hpp>

TEST(StringToByteTest, PositiveTest_Empty) {
  buffer_t result_ = verified::utils::StringToBytes("");
  buffer_t compare_vect_ {};

  EXPECT_EQ(compare_vect_, result_);
}

TEST(StringToByteTest, NegativeTest_Empty) {
  buffer_t result_ = verified::utils::StringToBytes("");
  buffer_t compare_vect_ {0};

  EXPECT_NE(compare_vect_, result_);
}

TEST(StringToByteTest, PositiveTest_Value) {
  buffer_t result_ = verified::utils::StringToBytes("Rahul");
  buffer_t compare_vect_ {0x52, 0x61, 0x68, 0x75, 0x6c};

  EXPECT_EQ(compare_vect_, result_);
}

TEST(StringToByteTest, NegativeTest_Value) {
  buffer_t result_ = verified::utils::StringToBytes("Rahul");
  buffer_t compare_vect_ {0};

  EXPECT_NE(compare_vect_, result_);
}
