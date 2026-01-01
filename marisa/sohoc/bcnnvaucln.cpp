// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

long long u, v;
long long cnt;
long long gcd(long long a, long long b){
	if(b == 0)return a;
	return gcd(b, a%b);
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>u>>v;

	f0(i, u, v){
		long long a = i, b = u*v/i;
		if(gcd(a, b) == u && a*b/gcd(a, b) == v)cnt++;
	}

	cout<<cnt;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
