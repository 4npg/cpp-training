// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout << "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i, a, b) for (int (i) = (a); i <= (b); ++i)
#define fi first
#define se second
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    int n;
    cin >> n;
    vector<int> a(n + 1);
    FOR(i, 1, n) cin >> a[i];

    vector<pair<int, int>> res;
    FOR(i, 1, n - 1) {
        FOR(j, i + 1, n) {
            if (a[i] == a[j]) {
                res.emplace_back(i, j);
            }
        }
    }

    cout << res.size();
    el;
    for (auto x : res) {
        cout << x.fi << " " << x.se;
        el;
    }
}
