#define USE_AS_HEADER

#include "./boilerplate.cc" // NOLINT
#include <cassert>

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

int main(int argc, char **argv) {
    test_safehash();
    cout << "test passed!" << endl;
    return 0;
}
