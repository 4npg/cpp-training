// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005
#define pb push_back

vector<int> a[maxn];
int64 dp[maxn], sz[maxn], ans[maxn];
int n;

void dfs1(int u, int p){
	sz[u] = 1;
	dp[u] = 0;
	for(int v:a[u]){
		if(v==p)continue;
		dfs1(v,u);
		sz[u] += sz[v];
		dp[u] += dp[v] + sz[v];
	}
}

void dfs2(int u, int p){
    for(int v:a[u]){
        if(v==p) continue;
        ans[v] = ans[u] - sz[v] + (n - sz[v]);
        dfs2(v,u);
    }
}


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	f0(i,1,n-1){
		int u,v;cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}		

	dfs1(1,0);
	ans[1] = dp[1];
	dfs2(1,0);
	f0(i,1,n)cout<<ans[i]<<" ";

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


