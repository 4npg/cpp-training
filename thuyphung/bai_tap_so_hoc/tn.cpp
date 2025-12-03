#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tn"
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

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}

ll lcm(ll a,ll b){
	ll gcdab = gcd(a,b);
	return (a/gcd(a,b))*b;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    ll cur_lcm;
  	cin>>cur_lcm;
  	vector<ll>arr;
  	arr.pb(cur_lcm);
    FOR(i,1,n-1){
    	ll x;cin>>x;
    	cur_lcm = lcm(cur_lcm,x);
    	arr.pb(x);
    }
    cout<<cur_lcm<<endl;
    for(auto x:arr){
    	cout<<cur_lcm/x<<" ";
    }
}


