// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005

int n;
int t[maxn], r[maxn];
int dp[maxn];


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    f0(i, 1, n)cin>>t[i];
    f0(i, 2, n)cin>>r[i];

    dp[1] = t[1];
    f0(i, 2, n){
        dp[i] = min(dp[i-1] + t[i], dp[i-2]+r[i]);
    }

    cout<<dp[n];

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


