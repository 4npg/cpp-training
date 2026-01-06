// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "bai5"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n, m;
vector< pair<int, int> > a[maxn];

int timecnt = 0;
int tin[maxn], low[maxn];
bool vis[maxn], isbr[maxn];

void dfscau(int u, int p){
	tin[u] = low[u] = ++timecnt;
	for(auto top:a[u]){
		auto to = top.first; 
		auto id = top.second;

		if(id == p)continue;

		if(!tin[to]){
			dfscau(to, id);
			low[u] = min(low[u], low[to]);
			if(low[to] > tin[u]){
				isbr[id] = true;
			}
		}else{
			low[u] = min(low[u], tin[to]);
		}
	}
}

int dfscnt(int u){
	int cnt = 1;
	vis[u] = 1;
	for(auto top:a[u]){
		auto to = top.first;
		auto id = top.second;

		if(vis[to])continue;
		if(isbr[id])continue;

		cnt += dfscnt(to);
	}
	return cnt;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	f0(i, 0, m-1){
		int u, v; cin>>u>>v;
		a[u].emplace_back(v, i);
		a[v].emplace_back(u, i);
	}

	f0(i, 1, n){
		if(!tin[i])dfscau(i, -1);
	}

	long long ans = 0;

	f0(i, 1, n){
		if(!vis[i]){
			int sz = dfscnt(i);
			ans += 1LL * sz * (sz-1)/2;
		}
	}

	cout<<ans;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
