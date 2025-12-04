// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "task"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 3000006

int q;

int64 tcs(int n){
    int64 sum = 0;
    while(n){
        sum += n%10;
        n /=10;
    }
    return sum;
}

bool nto(int n){
    if(n<2)return 0;
    if(n==2 || n==3)return 1;
    if(n%2==0 || n%3==0)return 0;

    for(int i=5; i*i<=n; i++){
        if(n%i==0 || n%(i+2)==0)return 0;
    }
    return 1;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>q;
    while(q--){
        int l, r, cnt = 0;
        cin>>l>>r;
        f0(i, l, r){
            if(nto(i) && tcs(i)%5==0)cnt++;
        }
        cout<<cnt<<'\n';
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
