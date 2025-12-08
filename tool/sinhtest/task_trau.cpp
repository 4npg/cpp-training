// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "task"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 10004

int n, m;

int64 factor(int64 n){
    if(n==0 || n == 1)return 1;
    return n*factor(n-1);
}

int cnt(int64 n){
    int d = 0;
    for(int i=2; i<=n; i++){
        if(n%i==0){
            while(n%i==0){
                n/=i;
            }
            d++;
        }
    }
    return d;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>n>>m;

    cout<<cnt(factor(n)/(factor(m)*(factor(n-m))));

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
