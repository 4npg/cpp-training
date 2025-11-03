// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "CAU1"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int64 n,k;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n>>k;
    cout<< 5 * ((2*n+k-1)/k);

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
