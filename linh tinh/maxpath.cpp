// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "longest"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back
#define fi first 
#define se second 

int n;
vector< pair<int, int64> > a[maxn];
int64 d[maxn];
int par[maxn];

void dfs(int u){
	for(auto &node:a[u]){
		int v = node.fi;
		int64 w = node.se;
		if(v == par[u])continue;

		d[v] = d[u] + w;
		par[v] = u;
		dfs(v);
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 1, n-1){
		int u, v; cin>>u>>v;
		int64 w; cin>>w;
		a[u].pb({v, w});
		a[v].pb({u, w});
	}
	memset(d, -1, sizeof d);
	memset(par, 0, sizeof par);
	d[1] = 0;
	dfs(1);
	int64 di = LLONG_MIN;
	int ans = 0;
	f0(i, 1, n){
		if(di < d[i]){
			di = d[i];
			ans = i;
		}
	}
	memset(d, -1, sizeof d);
	memset(par, 0, sizeof par);
	d[ans] = 0;
	dfs(ans);


	di = LLONG_MIN;
	ans = 0;

	f0(i, 1, n){
		if(di < d[i]){
			di = d[i];
			ans = i;
		}
	}

	cout<<di;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
