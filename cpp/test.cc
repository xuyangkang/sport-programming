#include "./boilerplate.cc" // NOLINT

#define USE_AS_HEADER

#include <cassert>
#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}


// TODO(xuyang): a proper C++ test framework

void test_safehash() {
    auto h1 = mk_hashmap<string>();
    h1[1] = "good";
    assert(h1[1] == "good");
    safe_hashmap<string> h2 = mk_hashmap<string>();
    h2[2] = "good";
    assert(h2[2] == "good");

    safe_hashset s1 = mk_hashset();
    s1.insert(3);
    assert(s1.count(3));
    assert(!s1.count(4));

    auto s2 = mk_hashset();
    s2.insert(4);
    assert(s2.count(4));
    assert(!s2.count(3));
}

void test_argv() {
    int a = 0;
    writeln("a =", a);
}

void test_template_argument_deduction() {
    pair pii = {1, 2};
    assert(pii.first == 1);
    assert(pii.second == 2);
}

int main(int argc, char **argv) {
    test_safehash();
    test_argv();
    test_template_argument_deduction();
    cout << "test passed!" << endl;
    return 0;
}
