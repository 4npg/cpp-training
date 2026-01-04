// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 100005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)


int n, W;
int w[maxn], v[maxn];
long long sum = 0;
long long dp[105][maxn];

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>W;
    f0(i, 1, n)cin>>w[i]>>v[i], sum += v[i];

    f0(i, 0, n){
        dp[i][0] = 0;
    }

    f0(i, 1, sum){
        dp[0][i] = inf;
    }

    f0(i, 1, n){
        f0(j, 0, sum){
            dp[i][j] = dp[i-1][j];
            if(j >= v[i]){
                dp[i][j] = min(dp[i][j], dp[i-1][j-v[i]] + w[i]);
            }
        }
    }

    fd(i, n, 1){
        fd(j, sum, 1){
            if(dp[i][j] <= W){
                cout<<j;
                return 0;
            }
        }
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
