// std libraries
#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::map;
using std::max;
using std::min;
using std::pair;
using std::priority_queue;
using std::queue;
using std::set;
using std::sort;
using std::string;
using std::unique;
using std::unordered_map;
using std::unordered_set;
using std::vector;

// type alias
using int8 = int8_t;
using uint8 = uint8_t;
using int16 = int16_t;
using uint16 = uint16_t;
using int32 = int32_t;
using uint32 = uint32_t;
using int64 = int64_t;
using uint64 = uint64_t;

// constants
// TODO(xuyang): find a better one
const int INT_INF = 0x3f3f3f3f;
const int64 INT64_INF = 0x3f3f3f3f3f3f3f3fLL;


// Vector utils
template <class T>
vector<T> mk_vec(size_t size) {
    return std::move(vector<T>(size));
}

template <class T>
vector<T> mk_vec(size_t size, T val) {
    return std::move(vector<T>(size, val));
}

template <class T>
vector<vector<T>> mk_2dvec(size_t sz1, size_t sz2) {
    return std::move(vector<vector<T>>(sz1, vector<T>(sz2)));
}

template <class T>
vector<vector<T>> mk_2dvec(size_t sz1, size_t sz2, T val) {
    return std::move(vector<vector<T>>(sz1, vector<T>(sz2, val)));
}

template <class T>
vector<vector<vector<T>>> mk_3dvec(size_t sz1, size_t sz2, size_t sz3) {
    return std::move(vector<vector<vector<T>>>(sz1,
        vector<vector<T>>(sz2, vector<T>(sz3))));
}

template <class T>
vector<vector<vector<T>>> mk_3dvec(size_t sz1, size_t sz2, size_t sz3, T val) {
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
using safe_hashmap = unordered_map<int64, T, SafeHash>;

template <class T>
safe_hashmap<T> mk_hashmap() {
    return unordered_map<int64, T, SafeHash>();
}

using safe_hashset = unordered_set<int64, SafeHash>;
safe_hashset mk_hashset() {
    return unordered_set<int64, SafeHash>();
}

// Loops
#define CAT_(a, b) a ## b
#define CAT(a, b) CAT_(a, b)
#define VARNAME(Var) CAT(Var, __LINE__)
#define repeat(N) for (int VARNAME(it) = 0; VARNAME(it) < (N); VARNAME(it)++)
#define loop(ITER, N) for (int64 ITER = 0; ITER < (N); ITER++)
#define loopeq(ITER, N) for (int64 ITER = 0; ITER <= (N); ITER++)

template <class T>
vector<T> read_vec(size_t n) {
    vector<T> vec(n);
    loop(i, n) {
        cin >> vec[i];
    }
    return std::move(vec);
}

template <class T>
void read_vec(vector<T> &vec) {  // NOLINT
    for (auto &i : vec) {
        cin >> i;
    }
}

char PRINT_HELPER[] = " \n";
template <class T>
void println_vec(const vector<T> &vec) {
    int n = vec.size();
    loop(i, n) {
        cout << vec[i] << PRINT_HELPER[i == n - 1];
    }
}


template<typename... Args>
void readln(Args&... args) {
    ((cin >> args), ...);
}

template<typename... Args>
void writeln(Args... args) {
    ((cout << args << " "), ...);
    cout << endl;
}

template<typename... Args>
void debug(Args... args) {
    #ifdef LOCAL
    #ifndef ONLINE_JUDGE
    cerr << endl;
    ((cerr << args << " "), ...);
    cerr << endl;
    #endif
    #endif
}

string yesno(bool ans) {
    return ans ? "YES" : "NO";
}

// entrance
const bool MULTI_CASES = true;

struct Context {
};
Context ctx;

void init();
void solve();

#ifndef USE_AS_HEADER

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases = 1;
    if (MULTI_CASES) {
        cin >> cases;
    }
    Context ctx;
    init();
    repeat(cases) {
        solve();
    }
    return 0;
}

// Global init, such as primes.
void init() {
}

// problem solver
void solve() {
}

#endif
