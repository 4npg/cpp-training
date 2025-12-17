// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "CAU2"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define inf (int64)4e18

int n, k;
int64 h[maxn];
int64 ans = inf;
int64 prema[maxn], pre[maxn];
int64 sufma[maxn], suf[maxn];


i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    //freopen(file".out", "w", stdout);

    cin>>n>>k;

    prema[0] = 0;
    pre[0] = 0;
    sufma[n+1] = 0;
    suf[n+1] = 0;
    f0(i, 1, n)cin>>h[i];


    if (k == 0) {
        int64 mx = 0, sum = 0;
        for (int i = 1; i <= n; i++) {
            mx = max(mx, h[i]);
            sum += h[i];
        }
        cout << n * mx - sum;
        return 0;
    }

    f0(i, 1, n){
        prema[i] = max(prema[i-1], h[i]);
        pre[i] = pre[i-1] + h[i];
    }

    fd(i, n, 1){
        sufma[i] = max(sufma[i+1], h[i]);
        suf[i] = suf[i+1] + h[i];
    }

    f0(i, 0, n){
        int64 wl = i*prema[i] - pre[i];
        int64 wr = (n-i)*sufma[i+1] - suf[i+1];
        ans = min(ans, wl+wr);
    }


    cout<<ans;
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
