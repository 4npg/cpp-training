#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)

ll solve(ll n){
	if(n<10)return 0;
	ll cnt=0;
	while(n>=10){
		ll prod = 1;
		while(n>0){
			prod*=(n%10);
			n/=10;	
		}
		n=prod;
		cnt++;
	}
	return cnt;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    cout<<solve(n);
}


