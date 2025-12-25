// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i=(a); i<=(b);++i)
#define fd(i,a,b) for(int i=(a); i>=(b);--i)
#define file "thuthach"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 100005
#define inf (int64)1e18

int t;

int64 gcd(int64 a, int64 b){
    if(b == 0)return a;
    return gcd(b, a%b);
}

int64 lcm(int64 a, int64 b){
    return a/gcd(a, b) * b;
}

int64 check(int64 mid, int64 a, int64 b){
    return mid - mid/a - mid/b + mid/lcm(a, b);
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);

    cin>>t;
    while(t--){
        int64 k, a, b;
        cin>>k>>a>>b;
        if(a == 1 || b == 1){
            cout<<0<<'\n';
        }else{
            int64 res = -1;
            int64 l = 1, r = inf;

            while(l<=r){
                int64 mid = l + (r-l)/2;
                if(check(mid, a, b)>=k){
                    res = mid;
                    r = mid - 1;
                }else l = mid + 1;
            }

            cout<<res<<'\n';
        }

    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
