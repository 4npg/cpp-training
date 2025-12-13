// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "DIVBLE"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

mt19937 rd(time(0));

int Rand(int l, int r){
    return l + rd()%(r-l+1);
}

void sinh(){
    ofstream cout(file".inp");

    int n = Rand(1, 1000000);
    cout<<n<<'\n';
    f0(i, 1, n){
        int a = Rand(1, 100000000000);
        cout<<a<<" ";
    }
}
int32_t main(){

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
