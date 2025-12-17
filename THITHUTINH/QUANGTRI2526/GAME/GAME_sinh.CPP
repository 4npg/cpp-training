// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file ""

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());


int Rand(int l, int r){
    return l+rng()%(r-l+1);
}

int64 Randl(int64 l, int64 r){
    return l+rngl()%(r-l+1);
}

void sinh(){
    ofstream cout(file".inp");


}

#define maxn 1000000

i_love_Hoang_Ngan(){

    f0(i, 1, maxn){
        sinh();

        system(file);
        system(file"_trau");

        if(system("fc " file".out " file".ans")){
            cout<<"Wrong";
            break;
        }
        cout<<"Correct\n";
    }


    cerr << "time elapsed: "<<TIME <<"s.\n";
}
