// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

bool nto(long long n){

    if(n<2)return false;
    if(n==2)return true;

    for(int i = 2; i*i<=n; i++){
        if(n%i==0)return false;
    }
    return true;
}

bool nt2(long long n){
    if(n<2)return false;
    if(n==2||n==3)return true;

    if(n%2==0 || n%3==0)return false;

    for(int i = 5; i*i<=n; i+=2){
        if(n%i==0 || n%(i+2)==0)return false;
    }
    return true;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cout<<nt2(937);

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


