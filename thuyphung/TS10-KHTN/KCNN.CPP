#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "KCNN"
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
    ll n; cin >> n;
    vector<ll> a(n);
    FOR(i,0,n-1) cin >> a[i];
    unordered_map<ll, ll> lsi;
    ll res = LLONG_MAX;
    FOR(i,0,n-1){
        ll idx = a[i];
        if(lsi.find(idx) != lsi.end()){
            res = min(res, i - lsi[idx]);
        }
        lsi[idx] = i;
    }
    cout << (res == LLONG_MAX ? -1 : res);
}
