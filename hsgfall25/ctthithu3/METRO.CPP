// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "METRO"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define mod 1000000007

int n;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    // freopen(file".out","w",stdout);

    cin>>n;
    vector<int> c(n+2);
    vector<int> l(n+1), r(n+1);
    f0(i,1,n)cin>>c[i];
    f0(i,1,n)cin>>l[i]>>r[i];

    vector<int> cnt(n+2,0), dp(n+2);
    vector<int> sum_cnt(n+2,0), sum_dp(n+2);

    cnt[n] = 1, dp[n] = 0;
    sum_cnt[n] = 1, sum_dp[n] = 0;

    for(int i=n-1;i>=1;i--){
        int lo = i+l[i];
        int hi = i+r[i];
        if(lo>hi)lo = n+1;
        if(hi>n)hi = n;
        if(lo>hi){
            cnt[i] = 0;
            dp[i] = 0;
        }else{
            cnt[i] = (sum_cnt[lo] - sum_cnt[hi+1] + mod)%mod;
            dp[i] = (sum_dp[lo] - sum_dp[hi+1] + c[i]*cnt[i] %mod + mod)%mod;
        }
        sum_cnt[i] = (cnt[i] + sum_cnt[i+1])%mod;
        sum_dp[i] = (dp[i]+ sum_dp[i+1])%mod;
    }
    cout<<dp[1] % mod;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
