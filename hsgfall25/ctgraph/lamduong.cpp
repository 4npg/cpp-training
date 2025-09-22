// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back

int n,m;
const int maxn = 1e5+5;
vector<int> a[maxn];
int vis[maxn];
int ans;

void dfs(int u){
	vis[u] = 1;
	for(int v:a[u]){
		if(!vis[v]){
			dfs(v);
		}
	}
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	f0(i,1,m){
		int u,v;
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}
	f0(u,1,n){
		if(!vis[u]){
			dfs(u);
			ans++;
		}
	}
	cout<<ans-1;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


