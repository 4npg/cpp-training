// author : anphung
#include <bits/stdc++.h>
using namespace std;
#define file "BAI1"
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

mt19937_64 rd(time(0));
int64 Rand(int64 l, int64 r){
    return l + rd() % (r - l + 1);
}

void sinh(){
    ofstream cout(file ".inp");
    int64 n = Rand(1, 1000);
    cout << n << "\n";
    for (int i = 0; i < n; i++)
        cout << Rand(1, 1'000'000) << " ";
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for (int test = 1; test <= 100000000; test++){
        sinh();
        system(file);
        system(file "_trau");

        system("cls");
        cout<<"Test "<<test<<" : ";
        if(system("fc " file".out " file".ans")){
            cout<<"Wrong";
            break;
        }
        cout<<"Correct\n";
    }
}
