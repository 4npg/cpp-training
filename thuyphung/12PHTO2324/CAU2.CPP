#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "CAU2"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll sum_func(ll n){
	ll sum = 0;
	while(n){
		sum+=n%10;
		n/=10;
	}
	return sum;
}
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll a,b;cin>>a>>b;
    ll n = gcd(a,b);
    ll res = LLONG_MIN;
    for(ll i=1;i*i<=n;i++){
    	if(n%i==0){
    		res = max(res,sum_func(i));
    		if(n/i!=i){
    			res = max(res,sum_func(n/i));
    		}
    	}

    }
    cout<<res;
}


