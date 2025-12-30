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
#define fi first 
#define se second 
#define pb push_back
#define pii pair<int, int>

int n, m, k;
int d[maxn], p[maxn];
bool vis[maxn];
vector<int> a[maxn];
int64 sum[maxn];

struct edge{
	int u, v;
};
	
vector<edge> g;

void bfs(int s){
	d[s] = 0;
	vis[s] = 1;
	queue<int> q; q.push(s);

	while(!q.empty()){
		int u = q.front(); q.pop();

		for(int &v:a[u]){
			if(!vis[v]){
				d[v] = d[u] + 1;
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m>>k;
	f0(i, 0, k-1)cin>>p[i];

	f0(i, 0, m-1){
		int u, v; cin>>u>>v; 
		a[u].pb(v);
		a[v].pb(u);
		g.pb({u, v});
	}

	f0(i, 0, k-1){
		memset(d, -1, sizeof d);
		memset(vis, 0, sizeof vis);
		bfs(p[i]);
		
		f0(e, 0, m-1){
			int u = g[e].u;
			int v = g[e].v;
			sum[e] += min(d[u], d[v]);
		}
	}

	int64 ans = inf;
	f0(e, 0, m-1){
		ans = min(ans, sum[e]);
	}

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
