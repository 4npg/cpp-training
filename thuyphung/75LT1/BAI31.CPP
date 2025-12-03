#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(a,b) for(ll i=(a);i<=(b);++i)

ll tinhtien(ll c, ll k) {
    ll t = 1;
    for (ll i = 0; i < k; ++i) t *= 10;
    return ((c + t / 2) / t) * t;
}
 


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll c,k;cin>>c>>k;
    cout<<tinhtien(c,k);
}


