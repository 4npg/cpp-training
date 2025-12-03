#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
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

    int n;
    cin >> n;
    if (n < 4) {
        cout << -1 << endl;
        return 0;
    }

    vector<ll> a(n);
    ll total_sum = 0;
    FOR(i, 0, n-1) {
        cin >> a[i];
        total_sum += a[i];     
    }

    sort(a.begin(), a.end(), greater<ll>());

    vector<ll> pref(n+1, 0);
    FOR(i, 0, n-1) {
        pref[i+1] = pref[i] + a[i];
    }

    int ans = -1;
    FOR(k, 0, n-4) {
        ll total_suffix = pref[n] - pref[k];
        ll top3 = a[k] + a[k+1] + a[k+2];
        if (2*top3 < total_suffix) {
            ans = k;
            break;
        }
    }

    cout << ans << endl;
}
