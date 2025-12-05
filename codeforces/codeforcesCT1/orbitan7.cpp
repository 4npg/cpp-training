#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

const ll maxn = 2e5 + 5; 
ll a[maxn];
ll b[maxn]; 
ll temp[maxn];

ll lis(ll n, ll xi, ll pi){
    FOR(i, 0, n - 1) temp[i] = a[i];
    temp[pi - 1] = xi;

    ll len = 0;
    FOR(i, 0, n - 1) {
        ll x = temp[i];
        ll pos = lower_bound(b, b + len, x) - b;
        b[pos] = x;
        if (pos == len) len++;
    }

    return len;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll n, q;
    cin >> n >> q;
    FOR(i, 0, n - 1) cin >> a[i];
    while (q--) {
        ll pi, xi;
        cin >> pi >> xi;
        cout << lis(n, xi, pi) << endl;
    }
}
