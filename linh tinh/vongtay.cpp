#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)
#define bit(mask,i) ((mask>>i)&1)
#define nl cout<<"\n"
ll n, m, s;
ll a[40];

void sub12() {
    ll total = (1 << n);
    ll cnt = 0;
    FOR(mask, 0, total - 1) {
        if (__builtin_popcount(mask) == m) {
            ll sum = 0;
            FOR(i, 0, n - 1)
                if (bit(mask, i)) sum += a[i];
            if (sum == s) cnt++;
        }
    }
    cout << cnt << "\n";
}

void sub3() {
    unordered_map<ll, ll> dp[40]; 
    dp[0][0] = 1;

    FOR(i, 1, n) {
        for (ll j = m; j >= 1; j--) {
            for (auto it : dp[j - 1]) {
                ll sum = it.first + a[i - 1];
                if (sum <= s) dp[j][sum] += it.second;
                cout<<"sum = "<<sum
                <<", it.fi = "<<it.first
                <<", a[i-1] = "<<a[i-1]
                <<", dp[i][sum] = "<<dp[j][sum]
                <<", it.se = "<<it.second;
                nl;
            }
        }
    }

    cout << dp[m][s];
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    cin >> n >> m >> s;
    FOR(i, 0, n - 1) cin >> a[i];

    if (n <= 18) sub12();  
    else sub3();           

}
