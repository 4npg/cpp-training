// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back
#define fi first 
#define se second 
#define pii pair<int, int>

int n, q;
int up[lg][maxn];
int h[maxn];
int d[maxn];

int lg2(int x){
	return x ? 31 - __builtin_clz(x) : -1;
}

vector<pii> a[maxn];

void dfs(int u){
	for(int &v:a[u]){
		if(v != up[0][u]){
			h[v] = h[u] + 1;
			up[0][v] = u;
			dfs(v);
		}
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n-1){
		int u, v; cin>>u>>v;
		a[u].pb({v, 1});
		a[v].pb({u, 1});
	}

	while(q--){
		int u, v, w; cin>>u>>v>>w;
	}

	// f0(i, 1, n){
	// 	cout<<i<<": ";
	// 	for(auto &node:a[i]){
	// 		cout<<node.fi<<" "<<node.se<<'\n';
	// 	}
	// 	cout<<'\n';
	// }
	

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
