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

// TODO: enable later
// template <class T>
// unordered_map<int64, T> mk_hashmap() {
//     return unordered_map<int64, T, SafeHash>();
// }

// template <class T>
// unordered_set<int64, SafeHash> mk_hashset() {
//     return unordered_set<int64, SafeHash>();
// }

// Loops
#define CAT_(a, b) a ## b
#define CAT(a, b) CAT_(a, b)
#define VARNAME(Var) CAT(Var, __LINE__)
#define repeat(N) for (int VARNAME(it) = 0; VARNAME(it) < (N); VARNAME(it)++)

#define FOR2(ITER, N) \
    for (int64 ITER = 0; ITER < (N); ITER++)
#define FOR3(ITER, START, END) \
    int64 VARNAME(step) = (START) <= (END) ? 1 : -1; \
    for (int64 ITER = (START); ITER < (END); ITER+=VARNAME(step))
#define FOR4(ITER, START, END, STEP) \
    int64 VARNAME(step)= (START) <= (END) ? (STEP) : -(STEP); \
    for (int64 ITER = (START); ITER < (END); ITER+=VARNAME(step))

#define TRIAGE_FOR(_1, _2, _3, _4, NAME, ...) NAME
#define loop(...) TRIAGE_FOR(__VA_ARGS__, FOR4, FOR3, FOR2)(__VA_ARGS__)


#define FOREQ2(ITER, N) \
    for (int64 ITER = 0; ITER <= (N); ITER++)
#define FOREQ3(ITER, START, END) \
    int64 VARNAME(step) = (START) <= (END) ? 1 : -1;\
    for (int64 ITER = (START); ITER <= (END); ITER+=VARNAME(step))
#define FOREQ4(ITER, START, END, STEP) \
    int64 VARNAME(step)= (START) <= (END) ? (STEP) : -(STEP); \
    for (int64 ITER = (START); ITER <= (END); ITER+=VARNAME(step))

#define TRIAGE_FOR_EQ(_1, _2, _3, _4, NAME, ...) NAME
#define loopeq(...) \
    TRIAGE_FOR_EQ(__VA_ARGS__, FOREQ4, FOREQ3, FOREQ2)(__VA_ARGS__)


// IO utils
#define crint(varname) int varname = 0; do { cin >> varname; } while (0)
#define crint64(varname) int64 varname = 0; do { cin >> varname; } while (0)
#define crdouble(varname) double varname = 0; do { cin >> varname; } while (0)

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

#define PRINTLN1(a) \
    do { \
        cout << (a) << endl; \
    } while (0)
#define PRINTLN2(a, b) \
    do { \
        cout << (a) << " " << (b) << endl; \
    } while (0)
#define PRINTLN3(a, b, c) \
    do { \
        cout << (a) << " " << (b) << " " << (c) << endl; \
    } while (0)
#define PRINTLN4(a, b, c, d) \
    do { \
        cout << (a) << " " << (b) << " " << (c) << " " << (d) << endl; \
    } while (0)
#define PRINTLN5(a, b, c, d, e) \
    do { \
        cout << (a) << " " << (b) << " " << (c) << " "; \
        cout << (d) << " " << (e) << endl; \
    } while (0)
#define PRINTLN6(a, b, c, d, e, f) \
    do { \
        cout << (a) << " " << (b) << " " << (c) << " "; \
        cout << (d) << " " << (e) << " " << (f) << endl; \
    } while (0)


#define TRIAGE_PRINTLN(_1, _2, _3, _4, _5, _6, NAME, ...) NAME
#define println(...) TRIAGE_PRINTLN(__VA_ARGS__, PRINTLN6, PRINTLN5, \
    PRINTLN4, PRINTLN3, PRINTLN2, PRINTLN1)(__VA_ARGS__)

string yesno(bool ans) {
    return ans ? "YES" : "NO";
}

// entrance
const bool MULTI_CASES = true;

struct Context {
};
void init(Context*);
void solve(const Context&);

#ifndef USE_AS_HEADER

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cases = 1;
    if (MULTI_CASES) {
        cin >> cases;
    }
    Context ctx;
    init(&ctx);
    repeat(cases) {
        solve(ctx);
    }
    return 0;
}

// Global init, such as primes.
void init(Context *ctx) {
}

// problem solver
void solve(const Context &ctx) {
}

#endif
