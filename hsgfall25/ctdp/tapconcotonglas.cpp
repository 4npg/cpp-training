// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back

int n,s;
const int maxn = 1e6+10;
int a[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	f0(i,1,n)cin>>a[i];
	vector<int>dp(s+1,-1);
	dp[0] = 0;
	f0(i,1,n){
		int v = a[i];
		for(int sum = s;sum>=v;sum--){
			if(dp[sum]==-1&&dp[sum-v]!=-1)dp[sum]=i;
		}
	}

	if(dp[s]==-1){
		cout<< -1 <<'\n';
		return 0;
	}

	vector<int> ans;
	int cur=s;
	while(cur){
		int idx = dp[cur];
		ans.pb(idx);
		cur-=a[idx];
	}
	cout<<ans.size()<<'\n';
	for(auto &val:ans)cout<<val<<" ";

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


