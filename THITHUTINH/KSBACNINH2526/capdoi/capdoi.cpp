// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i=(a); i<=(b);++i)
#define fd(i,a,b) for(int i=(a); i>=(b);--i)
#define file "capdoi"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn (int)1e6+1
#define fi first
#define se second
int n, m;

int64 res;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);

    cin>>n>>m;

    vector<int> cnta(maxn, 0);
    vector<int> cntb(maxn, 0);


    f0(i, 0, n-1){
        int x; cin>>x; cnta[x]++;
    }

    f0(i, 0, m-1){
        int x; cin>>x; cntb[x]++;
    }

    f0(i, 0, maxn-1){
        res += 1ll*cnta[i]*cntb[i];
    }

    cout<<res;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
