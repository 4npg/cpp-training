// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "TICHLN"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

int a[3];

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    int maxx=-1e6;
    int minn=1e6;
    int64 sum=0;
    FOR(i,0,2){
        cin>>a[i];
        maxx=max(a[i],maxx);
        minn=min(a[i],minn);
        sum+=a[i]*1ll;
    }
    cout<<(sum-maxx*1ll-minn*1ll)*maxx*1ll;

}


