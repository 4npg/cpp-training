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

#define maxn 200005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, q;

long long a[maxn], d[maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n)cin>>a[i];

	while(q--){
		int l, r; cin>>l>>r;
		long long v; cin>>v;
		d[l] += v;
		d[r+1] -= v;
	}

	f0(i, 1, n)d[i] += d[i-1];
	
	f0(i, 1, n){
		a[i] += d[i];
		cout<<a[i]<<" ";
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
