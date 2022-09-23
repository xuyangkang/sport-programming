// std libraries
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::pair;
using std::set;
using std::map;
using std::unordered_set;
using std::unordered_map;
using std::sort;
using std::unique;
using std::max;
using std::min;

// typedef
using int64 = int64_t;
using pii = pair<int, int>;

// constants
const int INT_INF = 0x3f3f3f3f;
const int64 INT64_INF = 0x3f3f3f3f3f3f3f3fLL;

// unordered_map anti-hack
#include <chrono>
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

// entrance
#define MULTI_CASES

void solve();

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases = 1;
#ifdef MULTI_CASES
    cin >> cases;
#endif
    while (cases--) {
        solve();
    }
    return 0;
}

// problem solver
void solve() {
}
