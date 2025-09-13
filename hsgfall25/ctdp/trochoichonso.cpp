// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int n;
const int maxn = 1e6+5;
int64 a[maxn];


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	vector<int64> pre(n+1,0);
	f0(i,1,n){
		cin>>a[i];
		pre[i] = pre[i-1] + a[i];
	}
	vector< vector<int64> > dp(n+1,vector<int64>(n+1,0));
	f0(i,1,n){
		dp[i][i] = a[i];
	}

	f0(len,2,n){
		for(int l=1;l+len-1<=n;++l){
			int r=l+len-1;
			dp[l][r] = pre[r]-pre[l-1] - min(dp[l+1][r],dp[l][r-1]);
		}
	}

	cout<<dp[1][n];
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


