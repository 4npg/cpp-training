// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "CAU4"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 100005
#define fi first
#define se second

int n;
int a[maxn];
int64 ans = 0;
int64 cal(int x){
    return 1ll*((x-1)*x)/2;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n;
    map<int,int> mp;
    f0(i,0,n-1){
        int x;cin>>x;
        mp[x]++;
    }

    for(auto &x:mp){
        //cout<<x.fi<<" "<<x.se<<'\n';
        ans += cal(x.se);
    }

    cout<<ans;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
