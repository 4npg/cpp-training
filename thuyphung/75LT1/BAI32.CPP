#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)

double fixZero(double x) {
    if (abs(x) < 1e-9) return 0.0;
    return x;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    double a,b,c,p,q,r;
    cin>>a>>b>>c>>p>>q>>r;
    double k = min({a/p,b/q,c/r});
    cout << fixed << setprecision(4)
    	 << fixZero(a - k*p) << " "
         << fixZero(b - k*q) << " "
         << fixZero(c - k*r);
}
