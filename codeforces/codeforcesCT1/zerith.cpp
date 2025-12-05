#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define endl "\n"
#define pb push_back
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

vector<ll> pfs(ll x){
	vector<ll> res;
    for (ll i = 2; i*i <= x; ++i) {
        if (x % i == 0) {
            res.push_back(i);
            while (x % i == 0) x /= i;
        }
    }
    if (x > 1) res.push_back(x);
    return res;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll left,right;cin>>left>>right;
    map<vector<ll>,ll>freq;
    FOR(i,left,right){
    	vector<ll>pf = pfs(i);
    	freq[pf]++;
    }
    ll res=0;
    for (auto x : freq) {
        res += 1LL * x.second * (x.second - 1) / 2;
    }
    cout<<res;
}


