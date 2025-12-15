// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "task"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

mt19937 rd(time(0));
mt19937_64 rng(time(0));

int64 Randll(int64 l, int64 r){
    return l+rng()%(r-l+1);
}

int Rand(int l, int r){
    return l + rd()%(r-l+1);
}

void sinh(){
    ofstream cout(file".inp");
    int n = Rand(1, 300005);
    cout<<n<<'\n';

    f0(i, 0, n-1){
        int a = Rand(1, 3000006);
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
