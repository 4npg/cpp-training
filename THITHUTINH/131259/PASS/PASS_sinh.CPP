// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file ""
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int Rand(int l, int r){
    return l+rng()%(r-l+1);
}
char c;

string sinh(){
    string xau = "";
    int dodaixau = Rand(1, 20);

    f0(i, 0, dodaixau-1){
        int luachon = Rand(1, 4);
        if(luachon == 1){
             c = Rand(97, 122);
        }else if(luachon == 2){
             c = Rand(65, 90);
        }else if(luachon == 3){
             c = Rand(48, 57);
        }else if(luachon == 4){
            int chonso = Rand(0, 7);
            int so[] = {33, 64, 35, 36, 37, 38, 42, 63};
             c = (char)so[chonso];
        }
        xau+=c;
    }
    return xau;
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
