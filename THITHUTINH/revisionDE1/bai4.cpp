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

vector<int> a[maxn];
bool vis[maxn];
int n, m;
int d[maxn];

void addEdge(int u, int v){
	a[u].emplace_back(v);
}

void bfs(int s, int &far, int &df){
	queue<int> q; q.push(s);
	d[s] = 0; vis[s] = 1;
	far = s; df = 0;

	while(q.size()){
		int u = q.front(); q.pop();
		far = u; df = d[u];

		for(int &v:a[u]){
			if(d[v] == -1){
				d[v] = d[u] + 1;
				vis[v] = 1;
				q.push(v);
			}
		}
	}



}

int dia(int s){
	memset(d, -1, sizeof d);
	int u, du;
	bfs(s, u, du);

	memset(d, -1, sizeof d);
	int v, dv; 
	bfs(u, v, dv);

	return dv+1;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	f0(i, 0, m-1){
		int u, v; cin>>u>>v;
		addEdge(u, v);
		addEdge(v, u);
	}

	long long ans = 0;
	f0(i, 1, n){
		if(!vis[i])ans += dia(i);
	}

	cout<<ans;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
