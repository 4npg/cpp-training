// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 200005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back
#define fi first 
#define se second

int n, q;
vector<int> a[maxn];
int h[maxn];
bool vis[maxn];
int par[maxn], sz[maxn];

void dfs(int u){
	
	for(int v:a[u]){
		if(v == par[u])continue;
		h[v] = h[u] + 1;
		par[v] = u;
		dfs(v);
	}
}

int lca(int u, int v){
	if(h[u] < h[v])swap(u, v);

	while(h[u] > h[v]){
		u = par[u];
	}

	while(u != v){
		u = par[u];
		v = par[v];
	}
	return u;
}

int lg2(int x){
	return x ? __builtin_clz(x) : -1;
}

int t[lg][maxn];

// void init(){
// 	f0(i, 0, n-1)t[0][i] = a[i];

// 	f0(j, 1, lg){
// 		for(int i=0; i + (1<<j)-1<n; ++i){
// 			t[j][i] = min(t[j-1][i], t[j-1][i + (1<<(j-1))]);
// 		}
// 	}
// }

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;

	f0(i, 0, n-1){
		int u, v; cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}

	h[1] = 0; par[1] = 1;
	dfs(1);

	cout<<lca(8, 10);
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
