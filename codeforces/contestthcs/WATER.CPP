#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll t;cin>>t;
    while(t--){
	    ll a,b,c;
	    cin>>a>>b>>c;
		cout << (abs(a - b) + 2 * c - 1) / (2 * c);
		nl;
	}

}


