// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//    return l+rng()%(r-l+1);
//}

#define maxn 20
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n;
long long x;
int p[maxn], t[maxn];

bool check(long long mid){
    long long s = 0;
    f0(i, 0, n-1){
        if(mid >= p[i]){
            long long cnt = 1 + (mid-p[i])/t[i];
            if(s >= x-cnt)return true;
            s += cnt;
        }
    }
    return s >= x;
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>x;
    f0(i, 0, n-1){
        cin>>p[i]>>t[i];
    }

    long long lo = 1, hi = 5e17, ans = -1;

    while(lo <= hi){
        long long mid = lo + (hi-lo)/2;
        if(check(mid)){
            ans = mid;
            hi = mid - 1;
        }else{
            lo = mid + 1;
        }
    }

    cout<<ans;
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
