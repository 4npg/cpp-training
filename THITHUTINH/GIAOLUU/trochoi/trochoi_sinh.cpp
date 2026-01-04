// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <=(b);++i)
#define fd(i,a,b) for(int i = (a); i >=(b);--i)
#define file "trochoi"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rngl(chrono::steady_clock::now().time_since_epoch().count());


int Rand(int l, int r){
    return l+rng()%(r-l+1);
}

long long Randl(long long l, long long r){
    return l+rngl()%(r-l+1);
}

void sinh(){
    ofstream cout(file".inp");
    int n = Rand(1, 20);
    cout<<n<<'\n';
    f0(i, 0, n-1){
        long long x = Randl(1, 1000000);
        cout<<x<<" ";
    }

}

#define maxn 1000000

con_meo_dua_leo(){

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


    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
