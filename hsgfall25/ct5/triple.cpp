// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

const int MOD = 1000000007;
int64 n;

int64 addmod(int64 x,int64 y){ 
    x+=y; 
    if(x>=MOD) x-=MOD; 
    return x; 
}
int64 mulmod(int64 x,int64 y){ 
    return (x%MOD)*(y%MOD)%MOD; 
}

int64 pw(int64 a,int64 b){
    int64 r=1;
    while(b){
        if(b&1) r = mulmod(r,a);
        a = mulmod(a,a);
        b >>= 1;
    }
    return r;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n;
    int64 S1=0, S2=0, S3=0;

    f0(i,1,n){
        int64 x; cin>>x;
        S1 = addmod(S1, x);
        S2 = addmod(S2, mulmod(x,x));
        S3 = addmod(S3, mulmod(mulmod(x,x), x));
    }

    int64 term1 = pw(S1,3);
    int64 term2 = mulmod(3, mulmod(S1,S2));
    int64 term3 = mulmod(2, S3);

    int64 res = term1;
    res = addmod(res, MOD - term2);
    res = addmod(res, term3);

    int64 inv6 = pw(6, MOD-2);
    res = mulmod(res, inv6);

    cout<<res;

    // cerr<<"time elapsed: "<<TIME<<"s.\n";
}
