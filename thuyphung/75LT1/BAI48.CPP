#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)

ll ipow(ll base, ll exp, ll mod) {
    ll res = 1 % mod;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

ll modPow2(ll n, ll m) {
    ll res = 1 % m;
    ll base = 2 % m;
    ll e = n - 1;
    while (e > 0) {
        if (e & 1) res = (res * base) % m;
        base = (base * base) % m;
        e >>= 1;
    }
    return res;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll a1, n;
    cin >> a1 >> n;

    const ll mod = 10000;
    const ll phi = 4000; 

    if (n == 1) {
        cout << a1 % mod << "\n";
        return 0;
    }

    ll e = modPow2(n, phi); 
    
    if (e == 0) e += phi;

    ll ans = ipow(a1, e, mod);
    cout << ans << "\n";


}


