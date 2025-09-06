// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back

int n;
const int maxn = 1e4+5;
int64 a[maxn];
int64 ans,lastpos;
int64 dp[maxn],trace[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	f0(i,0,n-1){
		cin>>a[i];
	}
	f0(i,0,n-1){
		dp[i] = 1;
		trace[i] = -1;
		f0(j,0,n-1){
			if(a[i]>a[j]&&dp[j]+1>dp[i]){
				dp[i] = dp[j]+1;
				trace[i] = j;
			}
		}
		if(dp[i]>ans){
			ans = dp[i];
			lastpos = i;
		}
	}
	cout<<ans<<'\n';
	vector<int64> lis;
	for(int i=lastpos;i!=-1;i=trace[i]){
		lis.pb(a[i]);
	}
	reverse(lis.begin(),lis.end());
	for(auto &x:lis)cout<<x<<" ";
}


