#include<bits/stdc++.h>
using namespace std;
#define file "chianhom"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int n;
int a[15],ans=1e9;

void Try(int pos, int sx, int sy, int sz) {
    if (pos == n) {
        if (sx == sy) ans = min(ans, sx + sz);
        return;
    }
    Try(pos+1, sx + a[pos], sy, sz);
    Try(pos+1, sx, sy + a[pos], sz);
    Try(pos+1, sx, sy, sz + a[pos]);
}

void sub1() {
    Try(0,0,0,0);
    cout<<ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);
    cin>>n;
    f0(i,0,n-1){
        cin>>a[i];
    }
    sub1();
    cerr<<'\n'<<"time elapsed: "<<TIME <<"s.\n";
}
