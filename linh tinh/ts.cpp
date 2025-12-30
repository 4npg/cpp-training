// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "xaudx"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 10004
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back

int n;
string s;
int dp[maxn][maxn];

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>s;
    //s = ' ' + s;

    string t = s;
    reverse(t.begin(), t.end());
    //t = ' ' + t;

    int n = s.size();
    dp[0][0] = 0;
    f0(i, 1, n){
        f0(j, 1, n){
            if(s[i-1] == t[j-1]){
                dp[i][j] = dp[i-1][j-1] + 1;
            }else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout<<dp[n][n]<<'\n';

    vector<char> ans;

    int i = n, j = n;

    while(i>0 || j>0){
        if(s[i-1] == t[j-1]){
            ans.pb(s[i-1]);
            i--;
            j--;
        }else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }else j--;
        }
    }

    reverse(ans.begin(), ans.end());
    for(auto &x:ans)cout<<x;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
