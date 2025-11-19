// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "CHIAQUA"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 200005

int n;
int64 v[maxn];
int64 res = LLONG_MAX;
int64 pre[maxn];


void sub2(){
    f0(k,1,n){
        //cout<<k<<" "<<pre[k]<<" "<<pre[n] - pre[k]<<'\n';
        res = min(res,abs(2*pre[k] - pre[n]));
    }
    cout<<res;
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n;
    pre[0] = 0;
    f0(i,1,n){
        cin>>v[i];
        pre[i] = pre[i-1] + v[i];
    }
    sub2();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
