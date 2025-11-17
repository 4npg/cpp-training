// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "CHEF"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 100005

int n;
int64 a[maxn];
int64 b[maxn];
int64 sumb;
int64 delta[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    // freopen(file".out","w",stdout);

    cin>>n;
    f0(i,0,n-1)cin>>a[i];
    f0(i,0,n-1){
        cin>>b[i];
        sumb += b[i];
    }

    f0(i,0,n-1)delta[i] = a[i] - b[i];

    sort(delta,delta+n,greater<int64>());
    vector<int64> pre(n+1);
    pre[0] = 0;
    f0(i,0,n-1){
        pre[i+1] = pre[i] + delta[i];
    }
    f0(i,0,n-1){
        cout<<sumb+pre[i+1]<<' ';
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
