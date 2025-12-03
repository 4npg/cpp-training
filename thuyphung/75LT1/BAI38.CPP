#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)

bool solve(ll l1,ll w1,ll h1,ll l2,ll w2,ll h2,ll lc,ll wc,ll hc){
	if(h1>hc||h2>hc)return false;
	vector<pair<ll,ll>> box1{{l1,w1},{w1,l1}};
	vector<pair<ll,ll>> box2{{l2,w2},{w2,l2}};

	for (auto x : box1)
    for (auto y : box2) {
        int x1 = x.first, y1 = x.second;
        int x2 = y.first, y2 = y.second;

        if (max(y1, y2) <= wc && x1 + x2 <= lc)
            return true;

        if (max(x1, x2) <= lc && y1 + y2 <= wc)
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
    ll t;
    cin>>t;
    while(t--){
    	ll l1,w1,h1,l2,w2,h2,lc,wc,hc;
    	cin>>l1>>w1>>h1>>l2>>w2>>h2>>lc>>wc>>hc;	

    	cout<<((solve(l1,w1,h1,l2,w2,h2,lc,wc,hc))?"YES":"NO");
    	nl;
    }
    


}


