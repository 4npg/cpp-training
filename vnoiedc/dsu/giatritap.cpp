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

#define maxn 300005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back
#define fi first
#define se second 

int n, m;

int par[maxn];
int sz[maxn];
int ma[maxn];
int mi[maxn];

void init(){
	f0(i, 1, n){
		par[i] = i;
		sz[i] = 1;
		ma[i] = i;
		mi[i] = i;
	}
}

int find(int v){
	return v==par[v]?v:par[v]=find(par[v]);
}

void uni(int a, int b){
	a = find(a);
	b = find(b);

	if(a == b)return;

	if(sz[a] < sz[b])swap(a, b);
	par[b] = a;
	sz[a] += sz[b];
	ma[a] = max(ma[a], ma[b]);
	mi[a] = min(mi[a], mi[b]);
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;

	init();

	while(m--){
		string s; cin>>s;
		int u, v;
		if(s == "union"){
			cin>>u>>v;
			uni(u, v);
		}else{
			cin>>u;
			int d = find(u);
			cout<<mi[d]<<" "<<ma[d]<<" "<<sz[d]<<'\n';
		}
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
