#include <gtest/gtest.h>

#include <utils/hex.hpp>

// EmptyByte positive test
TEST(EmptyByteTest, PositiveTest) {
  buffer_t compare_vect_ {0};
  buffer_t result_ = verified::utils::EmptyByte();

  EXPECT_EQ(compare_vect_, result_);
}

// EmptyByte Negative Test
TEST(EmptyByteTest, NegativeTest) {
  buffer_t compare_vect_ {0x63};
  buffer_t result_ = verified::utils::EmptyByte();

  EXPECT_NE(compare_vect_, result_);
}

// IsNumeric Positive Test
TEST(IsNumericTest, PositiveTest) {
  std::string value_ = "1234";
  bool result_ = verified::utils::IsNumeric(value_);

  EXPECT_TRUE(result_);
}

// IsNumeric Negative Test
TEST(IsNumericTest, NegativeTest) {
  std::string value_ = "abcd";
  bool result_ = verified::utils::IsNumeric(value_);

  EXPECT_FALSE(result_);
}

// IsHexPrefixed Positive Test
TEST(IsHexPrefixedTest, PositiveTest) {
  std::string value_ = "0x1234";
  bool result_ = verified::utils::IsHexPrefixed(value_);

  EXPECT_TRUE(result_);
}

// IsHexPrefixed Negative Test
TEST(IsHexPrefixedTest, NegativeTest) {
  std::string value_ = "1234";
  bool result_ = verified::utils::IsHexPrefixed(value_);

  EXPECT_FALSE(result_);
}

// InsertHexPrefix Positive Test
TEST(InsertHexPrefixTest, PositiveTest) {
  std::string compare_value_ = "0x67";
  std::string value_ = "67";
  std::string result_ = verified::utils::InsertHexPrefix(value_);

  EXPECT_EQ(compare_value_, result_);
}

// InsertHexPrefix Negative Test
TEST(InsertHexPrefixTest, NegativeTest) {
  std::string compare_value_ = "0x65";
  std::string value_ = "67";
  std::string result_ = verified::utils::InsertHexPrefix(value_);

  EXPECT_NE(compare_value_, result_);
}

// StringToByte Empty Positive Test
TEST(StringToByteTest, PositiveTest_Empty) {
  buffer_t compare_vect_ {};
  std::string empty_string_ = "";
  buffer_t result_ = verified::utils::StringToBytes(empty_string_);

  EXPECT_EQ(compare_vect_, result_);
}

// StringToByte Empty Negative Test
TEST(StringToByteTest, NegativeTest_Empty) {
  buffer_t compare_vect_ {0};
  std::string empty_string_ = "";
  buffer_t result_ = verified::utils::StringToBytes(empty_string_);

  EXPECT_NE(compare_vect_, result_);
}

// StringToByte Value Positive Test
TEST(StringToByteTest, PositiveTest_Value) {
  buffer_t compare_vect_ {0x52, 0x61, 0x68, 0x75, 0x6c};
  std::string value_string_ = "Rahul";
  buffer_t result_ = verified::utils::StringToBytes(value_string_);

  EXPECT_EQ(compare_vect_, result_);
}

// StringToByte Value Negative Test
TEST(StringToByteTest, NegativeTest_Value) {
  buffer_t compare_vect_ {0x53, 0x61, 0x68, 0x75, 0x6c};
  std::string value_string_ = "Rahul";
  buffer_t result_ = verified::utils::StringToBytes(value_string_);

  EXPECT_NE(compare_vect_, result_);
}
