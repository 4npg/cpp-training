// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;
const int maxn = 1e6+5;
int64 a[maxn];
int dp[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	f0(i,0,n-1)cin>>a[i];	
	int ans=0;
	f0(i,0,n-1){
		dp[i] = 1;
		f0(j,0,n-1){
			if(a[i]>a[j]){
				dp[i] = max(dp[i],dp[j]+1);
			}
		}
		ans = max(ans,dp[i]);
	}
	cout<<ans;
}


