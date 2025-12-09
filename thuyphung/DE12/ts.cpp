// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int64 a, b;
int k;

bool getcnt(int64 x, int k){
    int prev = -1;
    int cnt = 0;==
    while(x > 0){
        int d = x % 10;
        x /= 10;
        if(d == prev){
            cnt++;
        } else {
            cnt = 1;
            prev = d;
        }
        if(cnt >= k) return true;
    }
    return false;
}


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>a>>b>>k;
    int c = 0;
    for(int64 i=a; i<=b; ++i){
        if(getcnt(i, k))c++;
    }

    cout<<c;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}





