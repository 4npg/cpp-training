#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "PAFOWER"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)
#define maxn 1000

int dp[maxn+3][maxn+3], a[maxn+3], b[maxn+3];
int n;
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    cin>>n;
    FOR(i,1,n)cin>>a[i]>>b[i];
    FOR(i,1,n){
    	FOR(j,1,n){
    		if(a[i]==b[j]&&a[i]==-1){
    			dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
    		}else{
    			dp[i][j] = dp[i-1][j-1]+1;
    		}
    	}
    }
    cout<<dp[n][n];
}


