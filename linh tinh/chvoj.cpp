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
#define mod (int64)(1e9+7)
#define pli pair<int64, int>
#define fi first 
#define se second 
#define pb push_back

int n, m;
vector< pair<int, int64> > a[maxn];
int64 d[maxn];
int64 cnt[maxn];
int mied[maxn], maed[maxn];

void dijkstra(int s){
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	pq.push({0, s});
	d[s] = 0;
	cnt[s] = 1;
	mied[s] = maed[s] = 0;

	while(!pq.empty()){
		int64 du = pq.top().fi;
		int u = pq.top().se;
		pq.pop();

		if(du != d[u])continue;

		for(auto &node:a[u]){
			int v = node.fi;
			int64 w = node.se;

			if(d[v] > d[u] + w){
				d[v] = d[u] + w;
				cnt[v] = cnt[u]%mod;
				mied[v] = mied[u] + 1;
				maed[v] = maed[u] + 1;
				pq.push({d[v], v});
			}else if(d[v] == d[u] + w){
				cnt[v] = (cnt[v] + cnt[u])%mod;
				mied[v] = min(mied[v], mied[u]+1);
				maed[v] = max(maed[v], maed[u]+1);
			}
		}
	}

}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	f0(i, 0, m-1){
		int u, v; cin>>u>>v;
		int64 w; cin>>w;
		a[u].pb({v, w});
	}

	memset(d, 0x3f, sizeof d);
	memset(mied, 0x3f, sizeof mied);
	memset(maed, -0x3f, sizeof maed);
	dijkstra(1);

	cout<<d[n]<<" "<<cnt[n]<<" "<<mied[n]<<" "<<maed[n];

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
