// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "cau1"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

long long a, b, c;

long long mul(long long a, long long b){
	long long ans = 0;
	while(b){
		if(b&1)ans = (ans + a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>a>>b>>c;
	//cout<<max({mul(a, b), mul(a, c), mul(b, c)});

	cout<<max({(a%mod*b%mod)%mod, (a%mod*c%mod)%mod, (b%mod*c%mod)%mod});

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
