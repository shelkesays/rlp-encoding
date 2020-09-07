#include <gtest/gtest.h>

#include <utils/hex.hpp>


TEST(StringToByetTest, PositiveTest) {
  EXPECT_EQ(00000000, verified::utils::StringToBytes("").data());
  EXPECT_TRUE(true);
}
