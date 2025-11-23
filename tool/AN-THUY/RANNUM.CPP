// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "RANNUM"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 100005
#define fi first
#define se second
#define pb push_back

int n;
int a[maxn];


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n;
    map<int,vector<int>> p;
    f0(i,0,n-1){
        cin>>a[i];
        p[a[i]].pb(i+1);
    }
    int res = n;
    for(auto &x:p){
        auto v = x.se;
        int k = v[0];
        f0(i,1,(int)v.size()-1){
            k = max(k, v[i] - v[i-1]);
        }
        k = max(k,n+1 - v.back());
        res = min(res,k);
    }

    cout<<res;

    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
