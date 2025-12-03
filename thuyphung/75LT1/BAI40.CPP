#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)

ll lcs(vector<ll>& a) {
    ll n = a.size();
    ll res = 0;
    for (ll d = 2; d <= 1000; ++d) { 
        ll len = 0;
        for (ll i = 0; i < n; ++i) {
            if (a[i] % d == 0) {
                ++len;
                res = max(res, len);
            } else {
                len = 0;
            }
        }
    }
    return res;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    vector<ll> a(n);
    for(auto &x:a)cin>>x;
    cout<<lcs(a);

}


