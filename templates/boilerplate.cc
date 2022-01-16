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

typedef long long int64;

#define MULTI_CASES

void solve();

int main() {
#ifdef MULTI_CASES
    int cases;
    cin >> cases;
    while (cases--) {
        solve();
    }
#else
    solve();
#endif
    return 0;
}


void solve() {
}
