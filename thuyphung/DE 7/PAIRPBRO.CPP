//sang nguyen to, dem cap
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "PAIRPBRO"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)

const ll maxn = 1e7;
bitset<maxn> d;

void sang(){
	d[0]=d[1]=1;
	for(ll i=2;i*i<maxn;i++){
		if(d[i]==0){
			for(ll j=i*i;j<maxn;j+=i){
				d[j]=1;
			}
		}
	}
}


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll n,k;cin>>n>>k;
    sang();
    ll cnt=0;
    for(ll i=2;i+k<=n;i++){
    	if(d[i]==0&&d[i+k]==0)cnt++;
    }
    cout<<cnt;
}


