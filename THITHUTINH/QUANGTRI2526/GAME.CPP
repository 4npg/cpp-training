// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "GAME"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006

string s;
int cntl, cntr, cntu, cntd;
i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    cin>>s;

    for(auto &c:s){
        if(c=='L')cntl++;
        if(c=='R')cntr++;
        if(c=='U')cntu++;
        if(c=='D')cntd++;
    }


    int h = min(cntl, cntr);
    int v = min(cntu, cntd);
    int ans = -1;

    if(h > 0 && v > 0)
        ans = 2 * (h + v);
    else
        ans = -1;

    cout<<ans;

    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
