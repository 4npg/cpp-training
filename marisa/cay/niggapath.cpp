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

string s;
int n;
vector<int> a[maxn];
int ans;

void addEdge(int u, int v){
	a[u].emplace_back(v);
}

void dfs(int u, int p, int cnt){
	cnt += ((s[u] == '0')?1:-1);

	if(cnt > 0)ans++;

	for(int v:a[u]){
		if(v == p)continue;
		dfs(v, u, cnt);
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>s;
	f0(i, 1, n-1){
		int u, v; cin>>u>>v;
		addEdge(u, v);
		addEdge(v, u);
	}

	s = ' ' + s;

	dfs(1, 0, 0);

	cout<<ans;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
