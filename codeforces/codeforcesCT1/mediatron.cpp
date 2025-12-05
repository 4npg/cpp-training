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
const ll maxn=1e7*1ll;
ll a[maxn];

bool check(ll k, ll x, ll n) {
    ll cnt = 0;
    for (ll i = 0; i < k; ++i)
        cnt += (a[i] >= x);
    if (cnt >= k - (k - 1) / 2)
        return true;
    for (ll i = k; i < n; ++i) {
        cnt -= (a[i - k] >= x);
        cnt += (a[i] >= x);
        if (cnt >= k - (k - 1) / 2)
            return true;
    }
    return false;
}



int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n,x;cin>>n>>x;
    FOR(i,0,n-1)cin>>a[i];
    ll l=1,r=n,ans=0;
    while(l<=r){
    	ll mid = l + (r-l)/2;
    	if(check(mid,x,n)){
    		ans = mid;
    		l=mid+1;
    	}else{
    		r = mid - 1;
    	}
    }
    cout<<ans;
}


