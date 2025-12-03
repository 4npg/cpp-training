#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define TASK "THUONG"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll n, m;
    cin >> n >> m;

    vector<ll> a(n);
    unordered_map<ll, ll> d;

    for (ll i = 0; i < n; ++i) {
        cin >> a[i];
        d[a[i]]++;
    }

    for (ll i = 0; i < m; ++i) {
        ll x;
        cin >> x;
        d[x] = 0;
    }

    vector<ll> thua;
    for (auto x : a) {
        if (d[x] > 0) {
            thua.pb(x);
        }
    }

    if (thua.empty()) {
        cout << "0\n0\n";
        return 0;
    }
    for (auto x : thua) {
        cout << x << " ";
    }
    cout << "\n";

    unordered_map<ll, ll> cnt;
    ll res = 0;
    for (auto x : thua) {
        cnt[x]++;
        res = max(res, x * cnt[x]);
    }

    cout << res << "\n";

}