#include <exception>

#include <gtest/gtest.h>

#include <rlpencoding/utils/hex.hpp>

// HexToInteger Positive Test
TEST(HexTest, SafeParseInt_with_empty_string) {
    std::string value_ {""};

    EXPECT_ANY_THROW(verified::utils::SafeParseInt(value_));
}

