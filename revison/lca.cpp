// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 200005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, q;

int h[maxn];
int up[lg][maxn];

vector<int> a[maxn];

int lg2(int x){
	return x?31-__builtin_clz(x):-1;
}

void dfs(int u){
	for(int &v:a[u]){
		if(v != up[0][u]){
			up[0][v] = u;
			h[v] = h[u] + 1;
			dfs(v);
		}
	}
}

void init(){
	f0(j, 1, lg-1){
		f0(i, 1, n){
			up[j][i] = up[j-1][up[j-1][i]];
		}
	}
}

int lca(int u, int v){
	if(h[u] != h[v]){
		if(h[u] < h[v])swap(u, v);

		int k = h[u] - h[v];
		for(int j=0; (1<<j)<=k; ++j){
			if(k&(1<<j))u = up[j][u];
		}
	}
	
	if(u == v)return u;

	int k = lg2(h[u]);

	fd(j, k, 0){
		if(up[j][u] != up[j][v]){
			u = up[j][u];
			v = up[j][v];
		}
	}
	return up[0][u];
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n-1){
		int u, v; cin>>u>>v;
		a[u].emplace_back(v);
		a[v].emplace_back(u);
	}

	h[1] = 0;
	up[0][1] = 0;
	dfs(1);

	init();

	while(q--){
		int u, v; cin>>u>>v;
		cout<<lca(u, v)<<' ';
	}

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
