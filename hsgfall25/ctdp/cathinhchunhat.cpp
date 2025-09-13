// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int n,m;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;

	vector< vector<int> > dp(n+1,vector<int>(m+1,1e9));
	
	f0(i,1,n){
		f0(j,1,m){
			if(i==j)dp[i][j] = 0;
		else{
				f0(k,1,i-1){
					dp[i][j] = min(dp[i][j],dp[k][j]+dp[i-k][j]+1);
				}
				f0(k,1,j-1){
					dp[i][j] = min(dp[i][j],dp[i][k]+dp[i][j-k]+1);
				}
			}
		}
	}
	cout<<dp[n][m];
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


