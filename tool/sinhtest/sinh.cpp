// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "task"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rd(time(0));
int Rand(int l, int r){
    return l + rd()%(r-l+1);
}

int64 Rand64(int64 l, int64 r){
    return l + rd()%(r-l+1);
}
void sinh(){
    ofstream cout(file".inp");

    int n = Rand(1,100000);
    int k = Rand(1,100000);
    cout<<n<<" "<<k<<'\n';

    f0(i,0,n-1){
        int64 a = Rand64(1,1000000000);
        cout<<a<<" ";
    }
}
int32_t main(){

    f0(i,1,10000000){
        sinh();
        system(file);
        system(file"_trau");

        cout<<"Test "<<i<<" ";

        if(system("fc " file".out " file".ans")){
            cout<<"Wrong";
            break;
        }
        cout<<"Correct\n";
    }

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
