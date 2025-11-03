// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "CAU3"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 1000006

int n,k;
bool d[maxn];

void sang(){
    d[0] = d[1] = 1;
    for(int i = 2;i*i<maxn;++i){
        if(d[i] == 0){
            for(int j = i*i;j<maxn;j+=i){
                d[j] = 1;
            }
        }
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    sang();

    cin>>n>>k;
    int cnt = 0;
    f0(i,2,n-1){
        if(i+k<n&&!d[i]&&!d[i+k])cnt++;
    }
    cout<<(cnt==0?-1:cnt);
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
