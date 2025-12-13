// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "money"
#define int64 long long
#define f0(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rng(time(0));

int Rand(int l, int r){
    return l+rng()%(r-l+1);
}

void sinh(){
    ofstream cout(file".inp");

    int n = Rand(1, 100);
    int s = Rand(1, 1000000000);
    cout<<n<<" "<<s<<'\n';
    f0(i, 0, n-1){
        int a = Rand(1, 100);
        cout<<a<<" ";
    }

}

int32_t main(){

    f0(i, 1, 10000){
        sinh();

        system(file);
        system(file"_trau");

        if(system("fc " file".out " file".ans")){
            cout<<"Wrong";
            break;
        }

        cout<<"Correct\n";
    }

}
