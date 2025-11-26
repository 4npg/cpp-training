// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "COMPRESS"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define f0l(i,a,b) for(int64 (i) = (a); (i) <= (b); ++i)

int64 a,b;

void trau(int64 a, int64 b){
    int cnt = 0;
    for(int64 i=a; i<=b; ++i){
        for(int64 j = 2; j<= min(1ll*400,b); j++){
            if(i%j!=0){
                cnt += j-1;
                break;
            }
        }
    }
    cout<<cnt;
}


int cnt(int64 x) {
    int64 t = x;
    int d = 0;
    while(t != 2) {
        int64 nxt = 2;
        while(t % nxt == 0) nxt++;
        t = nxt;
        d++;
    }
    return d;
}

void sol(int64 a, int64 b) {
    int64 ans = 0;
    f0l(i,a,b)ans += cnt(i);
    cout << ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>a>>b;
    sol(a,b);
    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
