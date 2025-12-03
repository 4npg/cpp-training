#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "HCN"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define fi first
#define se second
#define pb push_back
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
    ll n;cin>>n;
    vector<pair<ll, ll>> rect(n);
    FOR(i, 0, n - 1) {
        ll d, r;
        cin>>d>>r;
        rect[i] = {1LL*d*r,d};
    }
    vector<pair<ll, ll>> last;
    for (auto x:rect) {
        ll l = 0, r = last.size();
        while (l < r) {
            ll m = l+(r-l)/2;
            if (last[m].fi > x.fi || 
               (last[m].fi == x.fi && last[m].se > x.se)) {
                l=m+1;
            } else {
                r=m;
            }
        }

        if (l==(ll)last.size())last.pb(x);
        else last[l] = x;
    }
    cout << last.size();
}
