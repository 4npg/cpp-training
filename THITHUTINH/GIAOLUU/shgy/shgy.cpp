// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "shgy"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 200005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)
#define pli pair<long long, int>

int n, m;
string s;
vector<int> a[maxn];
long long sumG, sumY;

long long dijkstra(int suc, char type){
	long long d[maxn];
	memset(d, 0x3f, sizeof d);
	priority_queue<pli, vector<pli>, greater<pli>> pq;
	d[suc] = 0;
	pq.push({0LL, suc});

	long long sum = 0;

	while(pq.size()){
		long long du = pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if(du != d[u])continue;

		for(int &v:a[u]){
			int tang = 0;
			if(s[v-1] != s[suc-1])tang = 3;
			long long nd = d[u] + (1 + tang)*1LL;
			if(d[v] > nd){
				d[v] = nd;
				pq.push({nd, v});
			}
		}
	}

	f0(u, 1, n){
		if(u == suc)continue;
		if(s[u-1] == type && suc < u)sum += d[u];
	}
	return sum;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m>>s;

	f0(i, 0, m-1){
		int u, v; cin>>u>>v;
		a[u].emplace_back(v);
		a[v].emplace_back(u);
	}

	f0(u, 1, n){
		if(s[u-1] == 'G')sumG += dijkstra(u, 'G');
		else sumY += dijkstra(u, 'Y');
	}

	cout<<sumG<<" "<<sumY;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
