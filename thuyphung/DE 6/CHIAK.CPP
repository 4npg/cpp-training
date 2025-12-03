#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "CHIAK"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n,k;cin>>n>>k;
    unordered_map<ll,ll>prf;
    prf[0]=1;
    ll prfsum = 0;
    ll res = 0;
    for(ll i=0;i<n;i++){
    	ll x;cin>>x;
    	prfsum+=x;
    	ll mod = ((prfsum%k)+k)%k;
    	//cout << "i=" << i << ", x=" << x << ", mod=" << mod << ", res=" << res << ", prf=" << prf[mod] << "\n";
    	res+=prf[mod];
    	prf[mod]++;
    }
    cout<<res;
}


