// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "MATCH"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define pb push_back

int n;
int64 l;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    // freopen(file".out","w",stdout);

    cin>>n>>l;

    vector<int64> a(n), b(n), c(n), d(n);

    f0(i,0,n-1)cin>>a[i];
    f0(i,0,n-1)cin>>b[i];
    f0(i,0,n-1)cin>>c[i];
    f0(i,0,n-1)cin>>d[i];

    vector<int64> ab;
    ab.reserve((int64)n*n);
    vector<int64> cd;
    cd.reserve((int64)n*n);

    f0(i,0,n-1){
        f0(j,0,n-1){
            ab.pb(a[i] + b[j]);
        }
    }

    f0(i,0,n-1){
        f0(j,0,n-1){
            cd.pb(c[i] + d[j]);
        }
    }

    sort(cd.begin(), cd.end());

    int64 ans = 0;
    for(auto x:ab){
        int64 target = l-x;
        int64 lo = lower_bound(cd.begin(),cd.end(),target)-cd.begin();
        int64 hi = upper_bound(cd.begin(),cd.end(),target)-cd.begin();
        ans += (hi-lo);
    }

    cout<<ans;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
