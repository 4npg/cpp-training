// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "trochoi"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int q;

long long cnt(long long x){
    long long dem = 0;
    for(int i = 1; i*i<=x; i++){
        if(x%i == 0){
            dem+=i;
            if(x/i!=i)dem+=x/i;
        }
    }
    return dem;
}

void sub1(){
    while(q--){
        long long x; cin>>x;
        cout<<cnt(x)<<" ";
    }
}

long long d[maxn];

void sang(){
    for(int i=2; i<maxn; i++){
        for(int j=i; j<maxn; j+=i)d[j]+=i;
    }
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".ans", "w", stdout);
    sang();
    cin>>q;
    while(q--){
        long long x; cin>>x;
        cout<<d[x]+1<<" ";
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
