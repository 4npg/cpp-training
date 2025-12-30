// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "moneysums"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 105
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)
#define pb push_back

int n;
vector<int> a(maxn);
bool f[maxn];
int sum = 0;
int dp[maxn][maxn];

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n;
    a.resize(n);
    f0(i, 0, n-1){
        cin>>a[i];
        sum += a[i];
    }
    f[0] = 1;
    for(auto &x:a){
        fd(su, sum, 0){
            if(su-x>=0 && f[su-x])f[su] = 1;
        }
    }

    vector<int> ans;
    f0(s, 1, sum){
        if(f[s])ans.pb(s);
    }

    cout<<ans.size()<<'\n';
    for(auto &x:ans){
        cout<<x<<" ";
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
