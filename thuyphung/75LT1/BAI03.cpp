// ??? bỏ dở
#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
#define ll long long
#define st string
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
void READFILE(){
    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
}
int main() {
    fast;
    ll n; cin >> n;
    ll xmax = -1e9, ymax = -1e9, xmin = 1e9, ymin = 1e9;
    for (ll i = 0; i < n; i++) {
        ll x, y; cin >> x >> y;
        xmax = max(xmax, x);
        xmin = min(xmin, x);
        ymax = max(ymax, y);
        ymin = min(ymin, y);
    }
    double w = xmax - xmin;
    double h = ymax - ymin;
    double res = sqrt(w * w + h * h);
    cout << fixed << setprecision(3) << res / 2.0;
    return 0;
}