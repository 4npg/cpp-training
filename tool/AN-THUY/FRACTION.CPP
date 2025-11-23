// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "FRACTION"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int b,n;
int64 cnt = 0;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>b>>n;

    int maxn = 2*n;
    int64 n2 = 1ll*n*n;

    for(int m = 1; m <= maxn; ++m){
        int64 tu= 1ll*b*m*(maxn-m);
        if((tu*1ll)%n2==0&&m!=n){
            cnt++;
        }
    }

    cout<<cnt;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
