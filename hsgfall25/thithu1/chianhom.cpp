// author : anphung
#include <bits/stdc++.h>
using namespace std;
#define file "chianhom"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 1000
#define maxs 100005
int n;
int a[maxn];
int dp[2][maxs];

void sub3(){
    memset(dp,-60,sizeof dp);
    dp[0][0] = 0;
    f0(i,1,n){
        int cur = i%2;
        int pre = 1-cur;

        memset(dp[cur],-60,sizeof dp[cur]);
        int x = a[i];
        f0(d,0,100000){
            if(dp[pre][d]<0)continue;
            dp[cur][d] = max(dp[cur][d],dp[pre][d]);

            if(x+d<maxs)dp[cur][x+d]=max(dp[cur][x+d],dp[pre][d]);

            int diff = abs(x-d);
            if(diff<maxs)dp[cur][diff] = max(dp[cur][diff],dp[pre][d]+min(x,d));
        }
    }
    cout<<accumulate(a+1,a+n+1,0LL)-dp[n%2][0];
}
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin>>n;
    f0(i,1,n){
        cin>>a[i];
    }
    sub3();
    cerr<<'\n'<<"time elapsed: "<<TIME <<"s.\n";
}

