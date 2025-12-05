#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "PROBLEM-B-THCS"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

const int maxn = 2005;
ll a[maxn][maxn];
ll n; 
ll tdc(ll x,ll y){
    ll res =0;
    while(x<=n&&y<=n){
        res+=a[x][y];
        x++;y++;
    }
    return res;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    FOR(i, 1, n)
        FOR(j, 1, n)
            cin >> a[i][j];

    ll res = LLONG_MIN;
    FOR(i,1,n){
        res = max(res,tdc(1,i));
    }
    FOR(i,1,n){
        res = max(res,tdc(i,1));
    }
    cout << res;
}
