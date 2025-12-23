// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define pb push_back

int n, m;
int d[maxn], st[maxn], en[maxn], tour[maxn];
vector<int> a[maxn];

void add(int u){
	tour[++m] = u;
	en[u] = m;
}

void dfs(int u, int paru){
	d[u] = d[paru] + 1;
	add(u);
	st[u] = m;
	for(int v:a[u]){
		if(v != paru){
			dfs(v, u);
		}
	}
	if(u != 1)add(paru);
}

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 1, n-1){
		int u, v;
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}

	dfs(1, 0);
	f0(i, 1, m)cout<<tour[i]<<" ";
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
