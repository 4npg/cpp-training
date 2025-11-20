// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file "BAI2"

mt19937_64 rd(time(0));
int Rand(int l, int r){
    return l + rd()% (r-l+1);
}

void sinh(){
    ofstream cout(file".inp");
    int n = Rand(1,1000);
    cout<<n<<'\n';
    f0(i,0,n-1){
        int a = Rand(1,1000);
        cout<<a<<" ";
    }
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    f0(i,1,100000000){
        sinh();
        system(file);
        system(file"_trau");

        cout<<"Test "<<i<<" : ";
        if(system("fc " file".out " file".ans")){
            cout<<"Wrong";
            break;
        }
        cout<<"Correct\n";
    }
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





