#include "boilerplate.h"

#define USE_AS_HEADER

#include <cassert>
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(BoilerPlateTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}


TEST(BoilerPlateTest, SafeHash) {
    auto h1 = mk_hashmap<string>();
    h1[1] = "good";
    EXPECT_EQ(h1[1], "good");
    safe_hashmap<string> h2 = mk_hashmap<string>();
    h2[2] = "good";
    EXPECT_EQ(h2[2], "good");

    safe_hashset s1 = mk_hashset();
    s1.insert(3);
    EXPECT_TRUE(s1.count(3));
    EXPECT_FALSE(s1.count(4));

    auto s2 = mk_hashset();
    s2.insert(4);
    EXPECT_TRUE(s2.count(4));
    EXPECT_FALSE(s2.count(3));
}

TEST(BoilerPlateTest, WritelnArgv) {
    int a = 0;
    writeln("a =", a);
}


TEST(BoilerPlateTest, TemplateArgumentDeduction) {
    pair pii = {1, 2};
    EXPECT_EQ(pii.first, 1);
    EXPECT_EQ(pii.second, 2);
}
