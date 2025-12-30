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

#define maxn 200008
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back
#define fi first 
#define se second 
#define pii pair<int, int> 

int s;
int n, q;
int h[maxn];
int64 d[maxn];
vector<int> a[maxn];
int up[lg][maxn];
bool vis[maxn];

int lg2(int x){
	return x ? 31 - __builtin_clz(x) : -1;
}

void dfs(int u){
	for(int &v:a[u]){
		if(v == up[0][u])continue;
		h[v] = h[u] + 1;
		up[0][v] = u;
		dfs(v);
	}
}

void bfs(int s){
	vis[s] = 1;
	h[s] = 0;
	up[0][s] = 0;
	queue<int> q;
	q.push(s);

	while(!q.empty()){
		int u = q.front(); q.pop();

		for(int &v:a[u]){
			if(!vis[v]){
				h[v] = h[u] + 1;
				up[0][v] = u;
				q.push(v);
			}
		}
	}
}

void init(){
	f0(j, 1, lg-1){
		f0(u, 1, n){
			up[j][u] = up[j-1][up[j-1][u]];
		}
	}
}

int lca(int u, int v){
	if(h[u] != h[v]){
		if(h[u] < h[v])swap(u, v);

		int k = h[u] - h[v];
		for(int j=0; (1<<j)<=n; ++j){
			if(k&(1<<j))u = up[j][u];
		}
	}
	if(u == v)return u;

	fd(j, k, 0){
		if(up[j][u] != up[j][v]){
			u = up[j][u];
			v = up[j][v];
		}
	}
	return up[0][u];
}

int dist(int u, int v){
	return h[u] + h[v] - 2*h[lca(u, v)];
}

int dia(vector<int> &gr){
	int a = gr[0], ma = 0, b = a, d;

	for(int x:gr){
		ma = d;
		b = x;
	}

	ma = 0;
	for(int x:gr){
		d = dist(b, x);
		ma = max(ma, d);
	}
	return ma;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n-1){
		int x, y;
		cin>>x>>y;
		a[x].pb(i);
		a[g[0][i]].pb(i);
		if(up[0][i] == 0)s = i;
	}

	h[s] = 0;
	up[0][s] = 0;
	dfs(s);

	f0(i, 1, k){
		cout<<dia(gr[i]);
	}
	
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
