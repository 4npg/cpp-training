#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(a,b) for(ll i=(a);i<=(b);++i)


ll dem(ll n, ll k) {
    if ((n + k) % 2 != 0 || n <= k) return 1;
    ll x = (n + k) / 2;
    ll y = (n - k) / 2;
    if (x <= 0 || y <= 0) return 1;
    return dem(x, k) + dem(y, k);
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n,k;cin>>n>>k;
    cout<<dem(n,k);

}


