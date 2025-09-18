// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int n;
const int maxn = 1e6+5;
int64 l,r;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>l>>r;
    vector<int64> a(n);
    f0(i,0,n-1){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    int64 ans = 0;
    f0(i,0,n-1){
        auto lo = lower_bound(a.begin()+i+1,a.end(),l-a[i]);
        auto hi = upper_bound(a.begin()+i+1,a.end(),r-a[i]);
        ans += hi-lo;
    }
    cout<<ans;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


