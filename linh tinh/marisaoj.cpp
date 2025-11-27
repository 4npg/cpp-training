// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 100005

int n,s;
int w[maxn], v[maxn];
int64 dp[maxn];


int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>s;    
    f0(i,1,n)cin>>w[i]>>v[i];
    dp[0] = 0;
    f0(i,1,n){
        for(int j = s; j>=w[i]; j--){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }
    cout<<dp[s];
    cerr << "time elapsed: "<<TIME <<"s.\n";
}





