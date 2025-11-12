// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n,m;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	vector< vector<int> > a(n,vector<int>(m));
	f0(i,0,n-1){
		f0(j,0,m-1){
			cin>>a[i][j];
		}
	}

	vector< vector<int> > dp(n+1,vector<int>(m+1,0));
	int mx = 0;

	f0(i,1,n){
		f0(j,1,m){
			if(a[i-1][j-1]==1){
				dp[i][j] = 1 + min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
				mx = max(mx,dp[i][j]);
			}
		}
	}

	int cnt = 0;
	if(mx>0){
		f0(i,1,n){
			f0(j,1,m){
				if(dp[i][j] == mx){
					cnt++;
				}
			}
		}	
	}else cnt=0;
	

	cout<<mx<<" "<<cnt;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


