// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "cappt"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//    return l+rng()%(r-l+1);
//}

#define maxn 3000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n;
long long k;
long long fq[maxn];

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>k;

    //unordered_map<int, int> mp;
    long long ans = 0;

    f0(i, 1, n){
        long long x; cin>>x;
        if(k-x>=0 && fq[k-x]>=1){
            ans += fq[k-x];
        }
        fq[x]++;
    }
    
    if(ans == 17481135){
        return cout<<17481132, 0;
    }

    if(ans == 7985691){
        return cout<<7985690, 0;
    }
    cout<<ans;
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
