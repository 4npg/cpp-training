#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define TASK "tenbai"
#define nl cout << "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll i = (a); i <= (b); ++i)

ll sumDigits(ll x) {
    ll s = 0;
    while (x > 0) {
        s += x % 10;
        x /= 10;
    }
    return s;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll n;
    cin >> n;

    ll ans = -1;
    ll sum = -1;

    ll limit = (ll)sqrt(n);
    for (ll i = 1; i <= limit; i++) {
        if (n % i == 0) {
            ll s_i = sumDigits(i);
            if (s_i > sum || (s_i == sum && i < ans)) {
                sum = s_i;
                ans = i;
            }

            ll nn = n / i;
            if (nn != i) {
                ll s_nn = sumDigits(nn);
                if (s_nn > sum || (s_nn == sum && nn < ans)) {
                    sum = s_nn;
                    ans = nn;
                }
            }
        }
    }

    cout << ans;
}
