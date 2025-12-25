// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define file "daybian"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

mt19937 rd(time(0));

int Rand(int l, int r){
    return l + rd()%(r-l+1);
}

void sinh(){
    ofstream cout(file".inp");

    int n = Rand(1, 1000);
    int s = Rand(1, 100);

    cout<<n<<" "<<s<<'\n';

    f0(i, 0, n-1){
        int a = Rand(-100, 100);
        cout<<a<<" ";
    }

}
con_meo_dua_leo(){

    f0(i,1,100000){
        sinh();
        system(file);
        system(file"_trau");

        if(system("fc " file".out " file".ans")){
            cout<<"Wrong";
            break;
        }
        cout<<"Correct\n";
    }

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
