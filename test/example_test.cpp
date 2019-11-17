#include "example.hpp"

#include <gtest/gtest.h>

TEST(Example, getTrue)
{
    EXPECT_TRUE(Example().getTrue());
}
