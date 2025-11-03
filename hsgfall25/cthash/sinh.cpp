// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "kstring"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rd(time(0));

int Rand(int l,int r){
    return l + rd() % (r-l+1);
}

void sinh(){
    ofstream cout(file".inp");
    int n = Rand(1, 10);
    int pick = Rand(1, 100);
    int k;
    if (pick <= 5) k = 0;
    else if (pick <= 10) k = n;
    else if (pick <= 15) k = n + Rand(1, 3);
    else k = Rand(0, n);

    string s;
    if (Rand(1, 10) == 1) {

        char c = 'a' + Rand(0, 2);
        s = string(n, c);
    } else {
        int alph = Rand(1, 3);
        for (int i = 0; i < n; ++i) s.push_back(char('a' + Rand(0, alph-1)));
    }

    cout << n << " " << k << "\n" << s << "\n";
    cout.close();
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    for(int i=1;i<=10000;i++){
        sinh();
        system(file);
        system(file"_trau");
        cout<<"Test "<<i<<"\n";
        if (system("fc "file".out "file".ans")){
            cout<<"Wrong";
            break;
        }
        cout<<"Correct\n";
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}

