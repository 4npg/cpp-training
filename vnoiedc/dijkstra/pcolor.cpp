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

int n, L, R, C, st, en;
int c[maxn];

vector< pair<int, int> > a[maxn];
long long d[maxn];

void addEdge(int u, int v, int w){
	a[u].emplace_back(v, w);
}

void Dijkstra(){
	f0(i, 1, n+1e5)d[i] = inf;

	priority_queue<data, vector<data>, greater<data>> q;
	q.emplace(d[st] = 0, st);

	while(q.size()){
		data x = q.top(); q.pop();
		long long du = x.first; int u = x.second;
		for(auto &p:a[u]){
			int v = p.first;
			long long w = p.second;
			if(d[v] > d[u] + w){
				q.emplace(d[v] = d[u] + w, v);
			}
		}
	}

	cout<<d[en];
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>L>>R>>C>>st>>en;

	f0(i, 1, n){
		if(i>1)addEdge(i, i-1, L);
		if(i<n)addEdge(i, i+1, R);
	}

	f0(i, 1, n){
		int c; cin>>c;
		addEdge(c+n, i, C);
		addEdge(i, c+n, 0);
	}

	Dijkstra();

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
