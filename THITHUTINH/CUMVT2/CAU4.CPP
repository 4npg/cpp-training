// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main() 
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006

int n;
int64 t[maxn], p[maxn];
int64 dp[maxn];


i_love_Hoang_Ngan{
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    f0(i, 1, n)cin>>t[i];
    f0(i, 2, n)cin>>p[i];

    dp[1] = t[1];
    f0(i, 2, n){
        dp[i] = min(dp[i-1] + t[i], dp[i-2]+p[i]);
    }

    cout<<dp[n];

    cerr << "time elapsed: "<<TIME <<"s.\n";
}