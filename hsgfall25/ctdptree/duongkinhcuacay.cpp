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
int dp[maxn];
int ans;

void dfs(int u, int p){
	int best1 = 0, best2 = 0;

	for(int v:a[u]){
		if(v==p)continue;

		dfs(v,u);

		int val = dp[v] + 1;
		if(val>best1){
			best2 = best1;
			best1 = val;
		}else if(val>best2){
			best2 = val;
		}
	}
	dp[u] = best1;

	ans = max(ans, best1+best2);
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	f0(i,1,n-1){
		int u,v;
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}
	memset(dp,0,sizeof(dp));
	dfs(1,0);
	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


