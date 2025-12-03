#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "MULTIPLE"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)

const ll mod = 2023;
ll n, r;

ll ipow(ll a, ll b) {
    ll res = 1;
    a %= mod;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}

void khongconghichdao() {
    ll lt = 1, sum = 1;
    for (ll i = 1; i < n; i++) {
        lt = (lt * r) % mod;
        sum = (sum + lt) % mod;
    }
    cout << sum;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> r;

    if (r == 1) {
        cout << n % mod << endl;
    } else {
        if (n <= 1000000) {
            khongconghichdao();
        } else {
            ll mau = (1 - r + mod) % mod;
            if (gcd(mau, mod) != 1) {
                khongconghichdao();
            } else {
                ll tu = (1 - ipow(r, n) % mod + mod) % mod;
                ll inv = ipow(mau, 1631);
                cout << tu * inv % mod << endl;
            }
        }
    }
}