#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "cprime"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif


bool prime(ll n){
	if(n<2)return false;
	if(n==2||n==3)return true;
	if(n%2==0||n%3==0)return false;
	for(ll i=5;i*i<=n;i+=6){
		if(n%i==0||n%(i+2)==0)return false;
	}
	return true;
}

ll rv_num(ll n){
	ll num = 0;
	while(n){
		num= num*10 + n%10;
		n/=10;
	}
	return num;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    cout<<((prime(n)&&prime(rv_num(n)))?"1":"0");
}


