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

int n, m;

struct edge{
	int v;
	long long p, w;
	edge(int _v, long long _p, long long _w){
		v = _v; p = _p; w = _w;
	}
};

struct node{
	int u; long long d;
	friend bool operator < (const node &a, const node &b){
		return a.d > b.d;
	}
};

struct dijkstra{
	int n;
	vector<vector<edge>> g;

	dijkstra(int _n){
		n = _n; g.assign(n+1, {});
	}

	void addEdge(int u, int v, long long p, long long w){
		g[u].emplace_back(v, p, w);
		g[v].emplace_back(u, p, w);
	}

	vector<long long> runminimax(int s){
		vector<long long> d(n+1, inf);
		priority_queue<node> pq;

		d[s] = 0;
		pq.push({s, 0});

		while(pq.size()){
			auto cur = pq.top(); pq.pop();
			int u = cur.u;
			if(cur.d != d[u])continue;

			for(auto &e:g[u]){
				int v = e.v;
				long long nd = max(d[u], e.p);
				if(nd < d[v]){
					d[v] = nd;
					pq.push({v, nd});
				}
			}
		}
		return d;
	}

	vector<long long> runweight(int s, long long lim_p){
		vector<long long> d(n+1, inf);
		priority_queue<node> pq;

		d[s] = 0;
		pq.push({s, 0});

		while(pq.size()){
			auto cur = pq.top(); pq.pop();
			int u = cur.u;
			if(cur.d != d[u])continue;

			for(auto &e:g[u]){
				if(e.p > lim_p)continue;
				int v = e.v;
				long long nd = d[u] + e.w;
				if(nd < d[v]){
					d[v] = nd;
					pq.push({v, nd});
				}
			}
		}
		return d;
	}
};

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;

	dijkstra dj(n);

	f0(i, 1, m){
		int u, v; cin>>u>>v;
		long long p, w; cin>>p>>w;

		dj.addEdge(u, v, p, w);
	}

	auto d1 = dj.runminimax(1);
	long long pstar = d1[n];

	auto d2 = dj.runweight(1, pstar);

	cout<<pstar<<" "<<d2[n];
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
