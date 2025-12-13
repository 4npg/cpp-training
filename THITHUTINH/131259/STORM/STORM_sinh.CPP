// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "STORM"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

mt19937 rd(time(0));

int Rand(int l, int r){
    return l + rd()%(r-l+1);
}

bool tontai0 = false;

void sinh(){
    ofstream cout(file".inp");

    int n = Rand(2, 1000);
    int m = Rand(2, 1000);

    cout<<n<<" "<<m<<'\n';

    f0(i, 1, n){
        f0(j, 1, m){
            int a;
            if(tontai0 == false){
                a = Rand(0, 2);
                if(a==0)tontai0 = true;
                else tontai0 = false;
            }else a = Rand(1, 2);

            cout<<a<<" ";
        }
        cout<<'\n';
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
