#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(a,b) for(ll i=(a);i<=(b);++i)


ll solve(ll d, ll k) {
    for (ll t = 1; t <= 18; ++t) {
        ll pow10 = 1;
        for (ll i = 0; i < t; ++i) pow10 *= 10;

        ll tu = d * pow10 - k * d;
        ll mau = 10 * k - 1;

        if (tu % mau != 0) continue;

        ll A = tu / mau;
        if (A < pow10 / 10) continue; 

        ll N = 10 * A + d;
        return N;
    }
    return -1;
}

int main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll t;
    cin >> t;
    while (t--) {
        ll d, k;
        cin >> d >> k;
        cout << solve(d, k) << '\n';
    }
}
