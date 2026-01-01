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

#define maxn 1000005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, m;
vector<int> a[maxn];

void addEdge(int u, int v){
	a[u].emplace_back(v);
}

bool vis[maxn];

void dfs(int u){
	for(int &v:a[u]){
		if(!vis[v]){
			vis[v] = 1;
			dfs(v);
		}
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	if(m != n-1){
		return cout<<"NO", 0;
	}else{

		while(m--){
			int u, v; cin>>u>>v;
			addEdge(u, v);
			addEdge(v, u);
		}

		int cnt = 0;

		f0(i, 1, n){
			if(!vis[i]){
				dfs(i);
				cnt++;
			}
		}
		cout<<((cnt == 1)?"YES":"NO");
	}

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
