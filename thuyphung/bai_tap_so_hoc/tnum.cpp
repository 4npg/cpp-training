#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tnum"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

const ll maxn = 1e7;
ll d[maxn];

void sang(){
	d[0]=d[1]=1;
	for(ll i=2;i*i<maxn;i++){
		if(d[i]==0){
			for(ll j=i*i;j<maxn;j+=i)d[j]=1;
		}
	}
}

bool cp(ll n){
	ll x = sqrtl(n);
	return (x*x==n);
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    sang();
    ll q;cin>>q;
    while(q--){
    	ll x;cin>>x;
    	ll num = sqrt(x);
    	cout<<((d[num]==0&&cp(x))?"YES":"NO")<<endl;
    }

}


