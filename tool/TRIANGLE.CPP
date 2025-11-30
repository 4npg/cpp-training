// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "TRIANGLE"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define pb push_back
#define all(a) (a).begin(),(a).end()

int n;


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n;
    vector<int64> r, g, b;
    f0(i,0,n-1){
        char c;int64 d;
        cin>>c>>d;
        if(c=='r'){
            r.pb(d);
        }else if(c=='g')g.pb(d);
        else b.pb(d);
    }

    sort(all(r));
    sort(all(g));
    sort(all(b));

    int64 cnt = 0;
    for(auto &x:r){
        for(auto &y:g){
            int64 lo = abs(x-y)+1, hi = x+y-1;
            if(lo>hi)continue;

            int64 lb = lower_bound(b.begin(),b.end(),lo) - b.begin();
            int64 ub = upper_bound(b.begin(),b.end(),hi) - b.begin();

            cnt += (ub-lb);
        }
    }

    cout<<cnt;
    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
