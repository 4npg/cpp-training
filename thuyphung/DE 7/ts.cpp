// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "eqlarray"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//    return l+rng()%(r-l+1);
//}

#define maxn 
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int t;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>t;
    while(t--){
        int k, n;
        cin>>n>>k;
        vector<long long> b(n, 0);
        long long s = 0;
        long long bm = -inf;
        f0(i, 0, n-1)cin>>b[i], s+=b[i], bm = max(bm, b[i]);

        cout<<((s%k == 0 && bm <= s/k)?"YES\n":"NO\n");
    }
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
