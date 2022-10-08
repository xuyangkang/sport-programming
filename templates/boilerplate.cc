// std libraries
#include <iostream>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <queue>

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
using std::queue;
using std::priority_queue;

// type alias
using int8 = int8_t;
using uint8 = uint8_t;
using int16 = int16_t;
using uint16 = uint16_t;
using int32 = int32_t;
using uint32 = uint32_t;
using int64 = int64_t;
using uint64 = uint64_t;

using pii = pair<int, int>;

// constants
// TODO(xuyang): find a better one
const int INT_INF = 0x3f3f3f3f;
const int64 INT64_INF = 0x3f3f3f3f3f3f3f3fLL;


// Vector utils
template <class T>
vector<T> mkVec(size_t size) {
    return std::move(vector<T>(size));
}

template <class T>
vector<T> mkVec(size_t size, T val) {
    return std::move(vector<T>(size, val));
}

template <class T>
vector<vector<T>> mk2dVec(size_t sz1, size_t sz2) {
    return std::move(vector<vector<T>>(sz1, vector<T>(sz2)));
}

template <class T>
vector<vector<T>> mk2dVec(size_t sz1, size_t sz2, T val) {
    return std::move(vector<vector<T>>(sz1, vector<T>(sz2, val)));
}

template <class T>
vector<vector<vector<T>>> mk3dVec(size_t sz1, size_t sz2, size_t sz3) {
    return std::move(vector<vector<vector<T>>>(sz1,
        vector<vector<T>>(sz2, vector<T>(sz3))));
}

template <class T>
vector<vector<vector<T>>> mk3dVec(size_t sz1, size_t sz2, size_t sz3, T val) {
    return std::move(vector<vector<vector<T>>>(sz1,
        vector<vector<T>>(sz2, vector<T>(sz3, val))));
}

// anti-hack for unordered_set and unordered_map
#include <chrono> // NOLINT
struct SafeHash {
    static uint64 splitmix64(uint64 x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64 x) const {
        static const uint64 FIXED_RANDOM =
            std::chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

struct Int64Equal {
    bool operator()(const int64 &i1, const int64 &i2) const {
        return i1 == i2;
    }
};

template <class T>
unordered_map<int64, T> mkSafeHashMap() {
    return unordered_map<int64, T, SafeHash>();
}

template <class T>
unordered_set<int64, SafeHash> mkSafeHashSet() {
    return unordered_set<int64, SafeHash>();
}

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
