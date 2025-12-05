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

bool cmp(ll a,ll b){
	return b>a;
}
const ll maxn = 1e7*1ll;
ll a[maxn];
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll n,k;cin>>n>>k;
    FOR(i,0,n-1)cin>>a[i];
    sort(a,a+n,cmp);
    ll res=0;
    for(ll i=n-1;i>=n-k;i--){
    	res+=a[i];
    }
    cout<<res;
}


