#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "DIEM-KHTNHN"
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
    ll q;cin>>q;
    ll maxr=LLONG_MIN, minr = LLONG_MAX;
    while(q--){
        ll x,y;
        cin>>x>>y;
        maxr = max(maxr,x+y);
        minr = min(minr,x+y);
    }
    cout<<maxr-minr;
}


