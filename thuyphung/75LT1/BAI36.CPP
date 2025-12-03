#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)

bool doixung(ll n){
	ll temp = 0;
	ll m = n;
	while(n){
		temp = temp * 10 + n%10;
		n/=10;
	}
	return temp==m;

}
ll cal_mir(ll n){
	ll temp = 0;
	while(n){
		temp = temp * 10 + n%10;
		n/=10;
	}
	return temp;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;cin>>n;
    while(!doixung(n)){
    	n+=cal_mir(n);
    }
    cout<<n;
}


