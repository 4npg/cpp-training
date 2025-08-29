// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define bitmask(mask,i) ((mask>>i)&1)
int n,t;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        if(n==0){
            cout<<0<<'\n';
            continue;
        }
        int hi = 31 - __builtin_clz(n);
        for(int i=hi;i>=0;--i){
            cout<<bitmask(n,i);
        }
        cout<<'\n';
    }
}


