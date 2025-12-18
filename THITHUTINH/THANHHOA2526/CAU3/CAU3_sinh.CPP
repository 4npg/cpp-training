// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define file "CAU3"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

mt19937 rd(time(0));

int Rand(int l, int r){
    return l + rd()%(r-l+1);
}

void sinh(){
    ofstream cout(file".inp");
    int n = Rand(1, 10000);
    int m = Rand(1, 10000);

    cout<<n<<" "<<m<<'\n';

    f0(i, 0, n-1){
        int a = Rand(1, 1000000);
        cout<<a<<" ";
    }
    cout<<'\n';
    f0(i, 0, m-1){
        int b = Rand(1, 1000000);
        cout<<b<<" ";
    }

}
i_love_Hoang_Ngan(){

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
