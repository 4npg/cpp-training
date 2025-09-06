// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,s;
int w[105],v[105];
const int maxn = 1e6+5;
int64 dp[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>s;
	f0(i,1,n)cin>>w[i]>>v[i];
	f0(i,1,n){
		for(int j=s;j>=w[i];j--){
			dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
		}
	}
	cout<<dp[s];
}


