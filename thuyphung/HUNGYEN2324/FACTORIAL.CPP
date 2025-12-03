#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "FACTORIAL"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL

#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif

const ll mod = 20240131;
const ll MAX_T = 243856;

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll n;cin>>n;
    if (n > MAX_T) n = MAX_T;
 
    ll sum = 0;
    ll fact = 1;
    for (ll i = 1; i <= n; ++i) {
        fact = (fact * i) % mod;
        sum = (sum + fact) % mod;
    }

    cout << sum;
}
