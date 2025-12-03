// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout << "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i, a, b) for (int (i) = (a); i <= (b); ++i)

int solve(int64 n) {
    if (n == 1) return 0;
    int64 len = 1;
    while (len * 2 < n) len *= 2;
    if (n <= len) return solve(n);
    return (solve(n - len) + 1) % 3;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    /*
    inp
    2
	4
	8
	out
	2
	0
	*/
    int t;
    cin >> t;
    while (t--) {
        int64 n;
        cin >> n;
        cout << solve(n) << "\n";
    }
}
