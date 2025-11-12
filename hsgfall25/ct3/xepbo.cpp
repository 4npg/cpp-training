// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define mod 20020303

int n,k;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>k;

	vector<int64> dp(n+1);
	dp[0] = 1;
	f0(i,1,n){
		dp[i] = dp[i-1];
		if(i>k){
			dp[i] = (dp[i]+dp[i-k-1])%mod;
		}else dp[i] = (dp[i]+1)%mod;
	}
	cout<<dp[n];
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


