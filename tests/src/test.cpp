#include <iostream>

#include <gtest/gtest.h>

#include <utils/hex.hpp>

// TEST(StringToByetTest, Zero) {
//   EXPECT_EQ(00000000, verified::utils::StringToBytes("").data());
//   EXPECT_TRUE(true);
// }

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
