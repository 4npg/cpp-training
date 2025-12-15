// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define file "TTNT"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int64 x, s, t;
int64 tg = 0;



mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return l + rng()%(r-l+1);
}

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    //cin>>x>>s>>t;

    x=1;
    s=1;
    t = (int64)1e9;

    bool state = 1;

    for(int i=1; tg<t; i++){
        if(i%2!=0){
            tg+=x;
            state = 1;
        }else{
            tg+=s;
            state = 0;
        }
    }
    cout<<state;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
