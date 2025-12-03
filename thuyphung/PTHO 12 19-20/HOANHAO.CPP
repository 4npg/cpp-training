#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "HOANHAO"
#define nl "\n"
#define oo 1e18
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL
#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

int main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n, k;
    cin >> n >> k;
    vector<ll> prefix(n+1, 0);
    FOR(i, 0, n-1) {
        ll x;
        cin >> x;             
        prefix[i+1] = prefix[i] + x;
    }

    double res = -oo;
    FOR(i, 0, n-1) {
        FOR(j, i, n-1) {
            ll sum = prefix[j+1] - prefix[i];
            ll len = j - i + 1;
            if (sum >= k) {
                res = max(res, double(sum) / len);
            }
            dbg(sum);
        }
    }

    cout << (ll)(floor(res)) << nl;
}
