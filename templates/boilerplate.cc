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

// entrance
#define MULTI_CASES

void solve();

int main(int argc, char **argv) {
    std::ios_base::sync_with_stdio(false);
    cin.tie(0);
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
