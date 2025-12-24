// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "travel"

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 200005
#define lg 20
#define pb push_back

struct edge{
	int to; 
	int64 c, e;
	int id;
};

int n;
vector<edge> a[maxn];
int par[lg][maxn], d[maxn];
int64 cnt[maxn];
int64 ans;

int U[maxn], V[maxn];
int64 C[maxn], E[maxn];

void dfs_init(int u, int p){
	par[0][u] = p;

	for(auto &ed:a[u]){
		int v = ed.to;
		if(v == p)continue;
		d[v] = d[u] + 1;
		dfs_init(v, u);
	}
}

int lca(int u, int v){
	if(d[u] < d[v])swap(u, v);

	fd(k, lg-1, 0){
		if(par[k][u] != -1 && d[par[k][u]] >= d[v]){
			u = par[k][u];
		}
	}

	if(u == v)return u;

	fd(k, lg-1, 0){
		if(par[k][u] != par[k][v]){
			u = par[k][u];
			v = par[k][v];
		}
	}
	return par[0][u];
}

void dfs_sum(int u, int p){
	for(auto &ed:a[u]){
		int v = ed.to;
		if(v == p)continue;

		dfs_sum(v, u);

		cnt[u] += cnt[v];

		int64 k = cnt[v];

		int64 cost = min(k * ed.c, ed.e);
		ans += cost;
	}
}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;

	f0(i, 1, n-1){
		cin>>U[i]>>V[i]>>C[i]>>E[i];

		a[U[i]].pb({V[i], C[i], E[i], i});
		a[V[i]].pb({U[i], C[i], E[i], i});
	}

	memset(par, -1, sizeof par);
	d[1] = 0;

	dfs_init(1, -1);

	f0(k, 1, lg-1){
		f0(i, 1, n){
			if(par[k-1][i] != -1)
				par[k][i] = par[k-1][par[k-1][i]];
		}
	}

	f0(i, 1, n-1){
		int u= i, v= i+1;
		int w = lca(u, v);
		cnt[u]++;
		cnt[v]++;
		cnt[w] -= 2;
	}

	dfs_sum(1, -1);

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
