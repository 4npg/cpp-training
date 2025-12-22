// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define file "task"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

mt19937 rd(time(0));

int Rand(int l, int r){
    return l + rd()%(r-l+1);
}

void sinh(){
    ofstream cout(file".inp");

    int type = Rand(1, 6);
    int n;

    if(type == 1){
        n = Rand(1, 100);
        cout << n << '\n';
        f0(i,1,n) cout << 0 << " ";
    }

    else if(type == 2){
        n = Rand(1, 100);
        cout << n << '\n';
        f0(i,1,n){
            if(i & 1) cout << 1 << " ";
            else cout << -1 << " ";
        }
    }

    else if(type == 3){
        n = Rand(1, 100);
        cout << n << '\n';
        f0(i,1,n){
            int64 x = (Rand(0,1) ? 1 : -1) * 1000000000LL;
            cout << x << " ";
        }
    }

    else if(type == 4){
        n = Rand(1, 100);
        cout << n << '\n';
        int cur = Rand(1, 10);
        f0(i,1,n){
            cur += Rand(1, 10);
            cout << cur << " ";
        }
    }

    else if(type == 5){
        n = Rand(1, 100);
        cout << n << '\n';
        int64 val = Rand(1, 100);
        f0(i,1,n){
            if(i % 4 == 1) cout << val << " ";
            else if(i % 4 == 2) cout << -val << " ";
            else if(i % 4 == 3) cout << val << " ";
            else cout << -val << " ";
        }
    }

    else{
        n = Rand(1, 100);
        cout << n << '\n';

        int i = 1;
        while(i <= n){
            int block = Rand(1,4);
            int len = Rand(1, min(50, n - i + 1));

            if(block == 1){
                f0(j,1,len) cout << 0 << " ";
            }
            else if(block == 2){
                f0(j,1,len){
                    if(j & 1) cout << 1 << " ";
                    else cout << -1 << " ";
                }
            }
            else if(block == 3){
                f0(j,1,len){
                    cout << Rand(-5,5) << " ";
                }
            }
            else{
                f0(j,1,len){
                    int64 x = (Rand(0,1) ? 1 : -1) * 1000000000LL;
                    cout << x << " ";
                }
            }
            i += len;
        }
    }
}

youngboiz_nobug(){

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
