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
#define data pair<long long, int>

int n, m;

struct graph{
	vector< pair<int, int> > a[maxn];

	void addEdge(int u, int v, int w){
		a[u].emplace_back(v, w);
	}

	long long d[maxn];

	void dijkstra(){
		f0(i, 1, n)d[i] = inf;
		d[1] = 0;

		priority_queue<data, vector<data>, greater<data>> q;

		q.emplace(d[1] = 0, 1);

		while(q.size()){
			data x = q.top(); q.pop();

			int du = x.first; int u = x.second;

			for(auto &p:a[u]){
				int v = p.first; int w = p.second;
				if(d[v] > d[u] + w){
					q.emplace(d[v] = d[u] + w, v);
				}
			}
		}
	}

} g[2];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	while(m--){
		int u, v, w; cin>>u>>v>>w;
		g[0].addEdge(u, v, w);
		g[1].addEdge(v, u, w);
	}

	f0(i, 0, 1)g[i].dijkstra();
	f0(i, 2, n){
		long long du = g[0].d[i] + g[1].d[i];
		if(du >= inf)du = -1;
		cout<<du<<"\n";
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
