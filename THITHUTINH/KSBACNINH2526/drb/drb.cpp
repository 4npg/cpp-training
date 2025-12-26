// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i=(a); i<=(b);++i)
#define fd(i,a,b) for(int i=(a); i>=(b);--i)
#define file "drb"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 12

int64 s1, s2, v1, v2;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>s1>>v1>>s2>>v2;

    if (v1 == v2 || (s2 - s1)*(v1 - v2) < 0)cout<<-1;
    else cout<< (s2 - s1) / (v1 - v2);

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
