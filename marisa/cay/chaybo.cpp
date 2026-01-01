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

#define maxn 100005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, k;
vector<int> a[maxn];

void addEdge(int u, int v){
	a[u].emplace_back(v);
}

int d[maxn];
bool vis[maxn];

void bfs(int s){
	d[s] = 0;
	vis[s] = 1;

	queue<int> q; q.push(s);

	while(q.size()){
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

	cin>>n>>k;
	f0(i, 1, n-1){
		int u, v; cin>>u>>v;
		addEdge(u, v);
		addEdge(v, u);
	}

	bfs(1);

	sort(d+1, d+n+1, greater<int>());

	int sum = 0;

	f0(i, 1, k){
		sum += d[i];
	}

	cout<<sum;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
