// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "cau1"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//    return l+rng()%(r-l+1);
//}

#define maxn 
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int a[8];
bool ok1 = true;
bool ok2 = true;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
     freopen(file".inp", "r", stdin);
     freopen(file".out", "w", stdout);

    f0(i, 0, 7)cin>>a[i];

    f0(i, 1, 6){
        if(a[i-1] < a[i] && a[i] < a[i+1]){
            ok2 = false;
        }

        if(a[i-1] > a[i] && a[i] > a[i+1]){
            ok1 = false;
        }
    }

    if(ok1 == true && ok2 == false){
        return cout<<"ascending", 0;
    }

    if(ok1 == false && ok2 == true){
        return cout<<"decending", 0;
    }

    if(ok1 == false && ok2 == false){
        return cout<<"mixed", 0;
    }
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
