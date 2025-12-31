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
#define fi first 
#define se second 
#define pb push_back

int n, m;
int par[maxn], sz[maxn];

void init(){
	f0(i, 1, n){
		par[i] = i;
		sz[i] = 1;
	}
}

int find(int v){
	return v == par[v] ? v : par[v] = find(par[v]);
}

void uni(int a, int b){
	a = find(a); b = find(b);

	if(a == b)return;

	if(sz[a] < sz[b])swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;

	init();

	while(m--){
		string s; int u, v;
		cin>>s>>u>>v;

		if(s == "union"){
			uni(u, v);
		}else{
			cout<<((find(u) == find(v)) ? "YES\n" : "NO\n");
		}
	}
	
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
