// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "SANPHAM"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 100005

int n;
int64 m;
int64 a[maxn];

bool check(int p){
    if(p == 0)return 0;
    int64 total = 0;
    for(auto &x:a){
        total += x/p;
        if(total>=m)return true;
    }
    return false;
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);

    cin>>n>>m;
    int64 lo = 1, hi = LLONG_MIN;
    int64 ans = -1;
    f0(i,0,n-1){
        cin>>a[i];
        hi = max(hi,a[i]);
    }

    while(lo <= hi){
        int64 mid = lo + (hi - lo)/2;
        if(check(mid)){
            ans = mid;
            lo = mid + 1;
        }else hi = mid - 1;
    }
    cout<<ans;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
