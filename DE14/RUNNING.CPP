	// author : anphung
	// github : 4npg  >>tqn
	#include<bits/stdc++.h>
	using namespace std;
	#define int64 long long
	#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

	int n,m;

	int32_t main(){
		ios::sync_with_stdio(0);cin.tie(0);
		cin>>n>>m;
		vector<int> d(n+1);
		f0(i,1,n)cin>>d[i];
		vector<vector<int>>dp(n+1,vector<int>(m+1,(-1e9)));
		dp[0][0] = 0;
		f0(i,0,n-1){
			f0(j,0,m){
				if(dp[i][j]<0)continue;
				if(j<m){
					dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j] + d[i+1]);
				}
				int mx = max(j-1,0);
				dp[i+1][mx] = max(dp[i+1][mx],dp[i][j]);
			}
		}
		cout<<dp[n][0];
	}


