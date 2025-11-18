// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "LUYENTAP"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 100005

int n;
int64 p,q;
int cnt;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);

    cin>>n>>p>>q;
    f0(i,0,n-1){
        int64 vi,wi;
        cin>>vi>>wi;
        if(vi>=p&&wi>=q)cnt++;
    }
    cout<<cnt;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
