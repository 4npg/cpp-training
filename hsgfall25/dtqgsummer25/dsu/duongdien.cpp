// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 4005
#define lg 13
#define pb push_back
#define fi first 
#define se second
#define pii pair<int, int64>

int n, m, q;
int par[maxn], sz[maxn];
int d[maxn], up[lg][maxn];
int64 mx[lg][maxn];

int64 msts = 0;

struct edge{
	int u, v, w;

	friend bool operator < (const edge &a, const edge &b){
		return a.w < b.w;
	}
};

vector<edge> e;
vector<pii> a[maxn];

void init(){
	f0(i, 1, n){
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	return v==par[v]?v:par[v] = find(par[v]);
}

bool uni(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)return false;
	if(sz[a] < sz[b])swap(a, b);

	par[b] = a;
	sz[a] += sz[b];
	return true;
}

void dfs(int u, int p){
	for(auto &po:a[u]){
		int v = po.fi;
		int64 w = po.se;
		if(v == p)continue;
		d[v] = d[u] + 1;
		up[0][v] = u;
		mx[0][v] = w;
		dfs(v, u);
	}
}

int64 lca(int u, int v){
	int64 res = 0;
	if(d[u] < d[v])swap(u, v);

	int dif = d[u] - d[v];

	f0(i, 0, lg-1){
		if(dif>>i&1){
			res = max(res, mx[i][u]);
			u = up[i][u];
		}
	}

	if(u == v)return res;

	fd(i, lg-1, 0){
		if(up[i][u] != up[i][v]){
			res = max({res, mx[i][u], mx[i][v]});
			u = up[i][u];
			v = up[i][v];
		}
	}
	return max({res, mx[0][u], mx[0][v]});
}

void kruskal(){
	sort(e.begin(), e.end());

	init();

	for(auto &ed : e){
	    if(uni(ed.u, ed.v)){
	        msts += ed.w;
	        a[ed.u].pb({ed.v, ed.w});
	        a[ed.v].pb({ed.u, ed.w});
	    }
	}

	d[1] = 0;
	up[0][1] = 0;
	mx[0][1] = 0;
	dfs(1, 0);

	f0(i, 1, lg-1){
		f0(v, 1, n){
			up[i][v] = up[i-1][up[i-1][v]];
			mx[i][v] = max(mx[i-1][v], mx[i-1][ up[i-1][v] ]);
		}
	}
}
youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	cin>>n>>m;	

	f0(i, 0, m-1){
		edge ed;
		cin>>ed.u>>ed.v>>ed.w;
		e.pb(ed);
	}
	kruskal();
	cin>>q;
	while(q--){
		int x, y;
		cin>>x>>y;
		cout<<msts - lca(x, y)<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
