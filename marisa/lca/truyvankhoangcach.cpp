// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005
#define lg 20
#define inf (int64)4e18
#define pb push_back
#define fi first 
#define se second
#define pli pair<int64, int>

int n, q;
vector<pli> a[maxn];
int h[maxn], up[lg][maxn];
int64 d[maxn];

int lg2(int x){
	return x ? 31 - __builtin_clz(x) : -1;
}

void dfs(int u){

	for(auto &node:a[u]){
		int v = node.fi;
		int64 w = node.se;
		if(v == up[0][u])continue;

		h[v] = h[u] + 1;
		d[v] = d[u] + w;
		up[0][v] = u;
		dfs(v);
	}
}

void bfs(int s){
	h[s] = 0;
	d[s] = 0;
	up[0][s] = 0;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int u = q.front(); q.pop();

		for(auto &node:a[u]){
			int v = node.fi; int64 w = node.se;

			if(v != up[0][u]){
				h[v] = h[u] + 1;
				d[v] = d[u] + w;
				up[0][v] = u;
				q.push(v);
			}
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


int64 get(int u, int v){
	return d[u] + d[v] - 2*d[lca(u, v)];
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n-1){
		int u, v; cin>>u>>v;
		int64 w; cin>>w;
		a[u].pb({v, w});
		a[v].pb({u, w});
	}

	// h[1] = 0;
	// d[1] = 0;
	// up[0][1] = 0;
	// dfs(1);
	bfs(1);
	init();

	while(q--){
		int u, v; cin>>u>>v;
		cout<<get(u, v)<<'\n';
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
