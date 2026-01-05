// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "cowland"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n, q;
int val[maxn];
vector<int> g[maxn];

int par[maxn];
int h[maxn];
int sz[maxn];
int pos[maxn];
int a[maxn];
int chainid[maxn];
int chainhead[maxn];
int curchain, curpos;

void dfs(int s, int p = -1){
	sz[s] = 1;
	for(int u:g[s]){
		if(u == p)continue;
		par[u] = s;
		h[u] = h[s] + 1;
		dfs(u, s);
		sz[s] += sz[u];
	}
}

void hld(int s, int p = -1){
	if(!chainhead[curchain]){
		chainhead[curchain] = s;
	}
	chainid[s] = curchain;
	pos[s] = curpos;
	a[curpos] = s;
	curpos++;
	int nxt = 0;
	for(int u:g[s]){
		if(u!=p){
			if(nxt == 0 || sz[u] > sz[nxt])nxt = u;
		}
	}

	if(nxt)hld(nxt, s);

	for(int u:g[s]){
		if(u != p && u != nxt){
			curchain++;
			hld(u, s);
		}
	}
}

int LCA(int u, int v){
	while(chainid[u] != chainid[v]){
		if(chainid[u] > chainid[v]){
			u = par[chainhead[chainid[u]]];
		}else{
			v = par[chainhead[chainid[v]]];
		}
	}
	if(h[u] < h[v])return u;
	return v;
}

int t[maxn*4];

void build(int id, int l, int r){
	if(l == r){
		t[id] = val[a[l]];
		return;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = t[id*2] ^ t[id*2+1];
}

void Upd(int id, int l, int r, int pos, int val){
	if(l>pos || r<pos)return;
	if(l == r && l == pos){
		t[id] = val;
		return;
	}

	int mid = (l+r)/2;
	Upd(id*2, l, mid, pos, val);
	Upd(id*2+1, mid+1, r, pos, val);

	t[id] = t[id*2] ^ t[id*2+1];
}

int calc(int id, int l, int r, int u, int v){
	if(v<l || r<u)return 0;
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;
	int tl = calc(id*2, l, mid, u, v);
	int tr = calc(id*2+1, mid+1, r, u, v);

	return tl^tr;
}

void update(int x, int val){
	Upd(1, 1, n, pos[x], val);
}

int query(int u, int v){
	int lca = LCA(u, v);	
	int ans = 0;

	while(chainid[u] != chainid[lca]){
		ans ^= calc(1, 1, n, pos[chainhead[chainid[u]]], pos[u]);
		u = par[chainhead[chainid[u]]];
	}

	while(chainid[v] != chainid[lca]){
		ans ^= calc(1, 1, n, pos[chainhead[chainid[v]]], pos[v]);
		v = par[chainhead[chainid[v]]];
	}

	if(h[u] < h[v]){
		ans ^= calc(1, 1, n, pos[u], pos[v]);
	}else{
		ans ^= calc(1, 1, n, pos[v], pos[u]);
	}

	return ans;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".in", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n){
		cin>>val[i];
	}

	f0(i, 1, n-1){
		int u, v; cin>>u>>v;
		g[u].emplace_back(v);
		g[v].emplace_back(u);
	}

	curpos = curchain = 1;
	dfs(1);
	hld(1);
	build(1, 1, n);

	while(q--){
		int type; cin>>type;
		if(type == 1){
			int x, val; cin>>x>>val;
			update(x, val);
		}else{
			int u, v; cin>>u>>v;
			cout<<query(u, v)<<'\n';
		}
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
