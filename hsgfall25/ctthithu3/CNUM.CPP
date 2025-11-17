// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "CNUM"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    // freopen(file".out","w",stdout);
    string s;
    getline(cin,s);
    int cnt = 0;
    for(auto &x:s)if(isdigit(x))cnt++;
    cout<<cnt;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
