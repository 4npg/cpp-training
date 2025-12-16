// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "MISS"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 100005

int64 n, q;
int64 a[maxn];

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    //freopen(file".out", "w", stdout);

    cin>>n>>q;
    f0(i, 1, n)cin>>a[i];

    while(q--){
        int64 k; cin>>k;

        int64 l = 0, r = n;
        while(l < r){
            int64 mid = (l+r+1)/2;
            int64 miss = a[mid] - mid;
            if(miss < k)l = mid;
            else r = mid-1;
        }

        int64 ans = a[l] + (k-(a[l]-l));
        cout<<ans<<'\n';
    }


    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
