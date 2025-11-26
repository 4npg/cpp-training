// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "GAME"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define inf 1e18
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int n,k;
vector<int> h;
int64 ans = 1e18;

void Try(int pos, int64 d){
    if(pos==n){
        ans = min(ans, d);
        return;
    }
    for(int i=1; i<=k && pos+i<=n;++i){
        Try(pos+i, d+abs(h[pos]-h[i+pos]));
    }
}

void trau(){
    Try(1,0);
    cout<<ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>n>>k;
    h.resize(n+1);

    f0(i,1,n)cin>>h[i];
    trau();
    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
