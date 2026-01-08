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

#define maxn 100005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)
#define pli pair<long long, int>

int n, m;

struct graph{
	vector<pair<int, long long>> ke[maxn];
	long long d[maxn];

	void addEdge(int u, int v, long long w){
		ke[u].emplace_back(v, w);
		ke[v].emplace_back(u, w);
	}

	void dijkstra(int s){
		d[s] = 0;
		priority_queue<pli, vector<pli>, greater<pli>> pq;
		pq.push({0LL, s}); 

		while(pq.size()){
			long long du = pq.top().first; int u = pq.top().second;
			pq.pop();

			if(du != d[u])continue;

			for(auto &p:ke[u]){
				int v = p.first; long long w = p.second;

				if(d[v] > d[u] + w){
					d[v] = d[u] + w;
					pq.push({d[v], v});
				}
			}
		}
	}
} g;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	f0(i, 0, m-1){
		int u, v; cin>>u>>v;
		long long w; cin>>w;

		g.addEdge(u, v, w);
	}

	memset(g.d, 0x3f, sizeof g.d);
	g.dijkstra(1);

	// cout<<g.d[n];

	vector<int> ans;

	f0(i, 1, n){
		if(g.d[i] > g.d[n]){
			ans.emplace_back(i);
		}
	}

	cout<<ans.size()<<'\n';
	for(auto &p:ans){
		cout<<p<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
