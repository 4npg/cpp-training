#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "QUA"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)

const ll maxn = 5e5+5;
ll a[maxn],w[maxn],dp[maxn];

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    for(ll i=0;i<n;i++){
    	cin>>a[i]>>w[i];
    }
    ll res = 0;
    for(ll i=0;i<n;i++){
    	dp[i] = w[i];
    	for(ll j=0;j<i;j++){
    		if(a[j]<a[i]){
    			dp[i] = max(dp[i],dp[j]+w[i]);
    		}
    	}
    	res=max(res,dp[i]);
    }
    cout<<res;
}


