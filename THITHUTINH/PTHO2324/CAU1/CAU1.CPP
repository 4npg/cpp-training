// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "CAU1"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn (int64)1e18

int64 n, k;
int cnt;

void sub1(){
    f0(i, 1, n){
        if(i<=(k-1)/2)cnt++;
    }
    cout<<cnt;
}

void sub2(){
    cout<<max(0LL, min(n, (k-1)/2) - max(1LL, k-n) + 1);
}
youngboiz_nobug(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n>>k;
    sub2();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
