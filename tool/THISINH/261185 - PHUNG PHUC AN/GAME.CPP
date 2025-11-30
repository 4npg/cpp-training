// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "GAME"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define inf 1e18
int n,k;
vector<int> h;
int64 ans = 1e18;

void Try(int pos, int64 d){
    if(pos==n){
        ans = min(ans, d);
        return;
    }
    for(int i=1; i<=k && pos+i<=n;++i){
        Try(pos+i, d+abs(h[pos]-h[i+pos]));
    }
}

void sol(){
    vector<int64> dp(n+1, inf);

    dp[1] = 0;
    f0(i,1,n){
        f0(j,i+1,min(n,i+k)){
            dp[j] = min(dp[j], dp[i] + abs(h[i] - h[j]));
        }
    }
    cout<<dp[n];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n>>k;
    h.resize(n+1);

    f0(i,1,n)cin>>h[i];

    Try(1, 0);
    cout<<ans;
    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
