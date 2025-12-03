// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file ""
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rd(time(0));
int Rand(int l,int r){
    return l + rd() % (r-l+1);
}

void sinh(){
    ofstream cout<<(file".inp");
    int n = Rand(1,5000);
    cout<<n<<'\n';
    f0(i,0,n-1){
        int a = Rand(1,(int)1e6);
        cout<<a<<' ';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i = 1;i<=10000;++i){
        sinh();
        system(file);
        system(file"_trau");
        cout<<"Test "<<i<<'\n';
        if(system("fc" file".out" file".ans")){
            cout<<"WRONG";
            break;
        }
        cout<<"Correct\n";
    }

    cerr << "time elapsed: "<<TIME <<"s.\n";
}

