#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
   	ll n;
    cin >> n;
    ll ans = 0;
    for (ll a = 0; a <= n; ++a) {
        ll cnt = n - a + 1;
        ans += cnt * a; 
        ans += 1LL * cnt * (n + a) / 2; 
    }
    cout << ans;

}


