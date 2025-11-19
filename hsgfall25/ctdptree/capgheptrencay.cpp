// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005
#define pb push_back

int n;
vector<int> a[maxn];
int dp[maxn][2];

void dfs(int u, int p){
	int sum0 = 0;
	for(int v:a[u]){
		if(v==p)continue;
		dfs(v,u);
		sum0 += max(dp[v][0], dp[v][1]);
	}
	dp[u][0] = sum0;
	dp[u][1] = 0;
	for(int v:a[u]){
		if(v==p)continue;
		dp[u][1] = max(dp[u][1], 1+dp[v][0] + sum0 - max(dp[v][0], dp[v][1]));
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

	dfs(1,0);
	cout<<max(dp[1][0],dp[1][1]);

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


