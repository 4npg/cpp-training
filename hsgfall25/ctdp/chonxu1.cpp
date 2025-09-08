// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

const int mod = 1e9+7;
int n,s;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	vector<int> a(n);
	for(auto &x:a)cin>>x;
	vector<int64> dp(s+1,0);
	dp[0] = 1;
	f0(x,1,s){
		for(int xu:a){
			if(x>=xu)dp[x] = (dp[x] + dp[x-xu])%mod;
		}
	}	
	cout<<dp[s];
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


