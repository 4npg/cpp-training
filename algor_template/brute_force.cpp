#include <bits/stdc++.h>
using namespace std;

/*
  Brute force templates:
  - generate permutations: next_permutation
  - generate combinations (bitmask)
  - recursive backtracking
*/

int n;
vector<int> a;

void brute_all_pairs() {
    for (int i = 0; i < n; ++i)
        for (int j = i+1; j < n; ++j)
            ; // xử lý (i,j)
}

void brute_bitmask() {
    for (int mask = 0; mask < (1<<n); ++mask) {
        // subset = elements with bit = 1
    }
}

void perm_example() {
    sort(a.begin(), a.end());
    do {
        // xử lý permutation a
    } while (next_permutation(a.begin(), a.end()));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}
