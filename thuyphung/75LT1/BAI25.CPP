#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(a,b) for(ll i=(a);i<=(b);++i)

ll gcd(ll a,ll b){
	if(b==0)return a;
	return gcd(b,a%b);
}
ll lcm(ll a,ll b){
	ll g = gcd(a,b);
	return a/gcd(a,b)*b;
}

ll solve(ll n,ll p,ll q,ll r){
	ll l1 = lcm(p,q);
	ll cnt1 = n/l1 - n/lcm(l1,r);

	ll l2 = lcm(p,r);
	ll cnt2 = n/l2 - n/lcm(l2,q);

	ll l3 = lcm(q,r);
	ll cnt3 = n/l3 - n/lcm(l3,p);
	return cnt1+cnt2+cnt3;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n,p,q,r;
    cin>>n>>p>>q>>r;
    cout<<solve(n,p,q,r);

}


