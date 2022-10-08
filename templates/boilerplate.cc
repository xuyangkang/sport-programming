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
#include <string>

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
using std::string;

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

template <class T>
unordered_map<int64, T> mkHashMap() {
    return unordered_map<int64, T, SafeHash>();
}

template <class T>
unordered_set<int64, SafeHash> mkHashSet() {
    return unordered_set<int64, SafeHash>();
}

// Loops
// TODO(xuyang): check if C++14 and 17 helps
#define times(N) for (int it##__LINE__ = 0; it##__LINE__ < (N); it##__LINE__++)
#define loop(iter, N) for (int iter = 0; iter < (N); iter++)

// IO utils
#define crint(varname) int varname = 0; do { cin >> varname; } while (0)
#define crint64(varname) int64 varname = 0; do { cin >> varname; } while (0)
#define crdouble(varname) double varname = 0; do { cin >> varname; } while (0)

template <class T>
vector<T> readVec(size_t n) {
    vector<T> vec(n);
    loop(i, n) {
        cin >> vec[i];
    }
    return std::move(vec);
}

template <class T>
void readVec(vector<T> &vec) {  // NOLINT
    for (auto &i : vec) {
        cin >> i;
    }
}

char PRINT_HELPER[] = " \n";
template <class T>
void println(vector<T> vec) {
    int n = vec.size();
    loop(i, n) {
        cout << vec[i] << PRINT_HELPER[i == n - 1];
    }
}

template <class T>
void println(T e) {
    cout << e << endl;
}

string toYesNo(bool ans) {
    return ans ? "YES" : "NO";
}

// DP utils
template <class T>
void updateMax(T &a, const T &b) { // NOLINT
    a = max(a, b);
}

template <class T>
void updateMin(T &a, const T &b) { // NOLINT
    a = min(a, b);
}

// entrance
#define MULTI_CASES

void solve();

#ifndef USE_AS_HEADER

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases = 1;
#ifdef MULTI_CASES
    cin >> cases;
#endif
    times(cases) {
        solve();
    }
    return 0;
}

// problem solver
void solve() {
}

#endif
