// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005
#define inf 4e18
int n;
int64 a[maxn], b[maxn];


int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    cin>>n;
    f0(i, 1, n)cin>>a[i];
    f0(i, 1, n)cin>>b[i];

    int64 a1 = a[0], a2 = -inf;
    int64 b1 = b[0], b2 = -inf;

    f0(i, 1, n){
        int64 na2 = a1 + a[i];
        int64 na1 = max(b1, b2) + a[i];
        int64 nb2 = b1 + b[i];
        int64 nb1 = max(a1, a2) + b[i];

        // cerr<< a1 << " " << a2 << " " << b1 << " " << b2 << '\n';
        // cerr<< na1 << " " << na2 << " " << nb1 << " " << nb2 << "\n\n";

        a1 = na1; a2 = na2;
        b1 = nb1; b2 = nb2;
    }

    cout<<max({a1, a2, b1, b2});
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}


