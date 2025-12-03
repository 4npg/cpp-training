#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout << "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i, a, b) for (ll (i) = (a); i <= (b); ++i)

ll solve(ll n, ll k) {
    if (n < 1 || n > (1LL << k)) return -1;

    ll lo = 1, hi = (1LL << k);
    ll layer = 1;
    while (lo < hi) {
        ll mid = lo + (hi - lo) / 2;
        if (n <= mid) {
            hi = mid;
            layer = layer * 2 - 1;
        } else {
            lo = mid + 1;
            layer *= 2;
        }
    }
    return layer;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll k, n;
    cin >> k >> n;
    cout << solve(n, k);
}
