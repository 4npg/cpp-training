// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//    return l+rng()%(r-l+1);
//}

#define maxn 200005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n; long long t;
long long x[maxn], h[maxn];
bool vis[maxn];

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n;

    f0(i,0,n-1)cin>>x[i]>>h[i];
    cin>>t;

    f0(i,0,n-1){
        if(vis[i]) continue;
        f0(j,i+1,n-1){
            if(vis[j]) continue;
            if(h[i] == h[j]) continue;

            long long tu = x[j] - x[i];
            long long mau = h[i] - h[j];
            if(tu % mau != 0) continue;
            long long num = tu / mau;
            if(num < 0 || num > t) continue;
            
            vis[i] = true;
            vis[j] = true;
            break;
        }
    }

    int ans = 0;
    f0(i,0,n-1) if(!vis[i]) ans++;

    cout << ans;
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
