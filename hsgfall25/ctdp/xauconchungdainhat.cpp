// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

string s,t;
int dp[3010][3010];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s>>t;	

	int n = s.size();
	int m = t.size();
	f0(i,1,n){
		f0(j,1,m){
			if(s[i-1]==t[j-1]){
				dp[i][j] = dp[i-1][j-1] +1;
			}else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
		}
	}
	cout<<dp[n][m];
}


