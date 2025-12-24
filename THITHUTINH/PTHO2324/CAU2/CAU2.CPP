// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "CAU2"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn (int64)1e9
#define pb insert

int64 a, b;
int u;

int tcs(int64 x){
    int sum = 0;
    while(x){
        sum += x%10;
        x/=10;
    }
    return sum;
}

int64 gcd(int64 a, int64 b){
    if(b == 0)return a;
    return gcd(b, a%b);
}

youngboiz_nobug(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);

    cin>>a>>b;

    int64 g = gcd(a, b);

    for(int i=1; i*i<=g; ++i){
        if(g%i==0){
            if(g/i!=i)u = max(u, tcs(g/i));
            u = max(u, tcs(i));
        }
    }

    cout<<u;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
