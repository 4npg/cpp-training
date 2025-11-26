// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "SOCHAN"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int64 n;

int64 s(int64 n){
    int64 sum = 0;
    while(n){
        sum += n%10;
        n/=10;
    }
    return sum;
}

void trau(){
    int64 cnt = 0;
    f0(i,1,n){
        if(s(i)%2==0){
            cnt++;
        }
    }
    cout<<cnt;
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>n;
    trau();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
