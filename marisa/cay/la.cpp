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

int n;
vector<int> a[maxn];

void addEdge(int u, int v){
	a[u].emplace_back(v);
}


con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	if(n == 1){
		return cout<<1, 0;
	}
	if(n == 2){
		return cout<<1, 0;
	}
	f0(i, 1, n-1){
		int u, v;
		cin>>u>>v;
		addEdge(u, v);
		addEdge(v, u);
	}

	int cnt = 0;

	f0(i, 1, n){
		if(a[i].size() == 1){
			cnt++;
		}
	}

	cout<<cnt;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
