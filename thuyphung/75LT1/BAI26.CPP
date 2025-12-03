#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout << "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll i=(a);i<=(b);++i)

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n;
    cin >> n;
    string s(n, ' ');
    ll cntx = 0, cntt = 0, cntd = 0;

    FOR(i, 0, n-1) {
        cin >> s[i];
        if (s[i] == 'X') cntx++;
        else if (s[i] == 'T') cntt++;
        else if (s[i] == 'D') cntd++;
    }

    string target = string(cntx, 'X') + string(cntt, 'T') + string(cntd, 'D');

    ll cnt = 0;
    ll xt = 0, tx = 0, xd = 0, dx = 0, td = 0, dt = 0;

    for (ll i = 0; i < n; ++i) {
        if (s[i] == 'X' && target[i] == 'T') xt++;
        if (s[i] == 'T' && target[i] == 'X') tx++;

        if (s[i] == 'X' && target[i] == 'D') xd++;
        if (s[i] == 'D' && target[i] == 'X') dx++;

        if (s[i] == 'T' && target[i] == 'D') td++;
        if (s[i] == 'D' && target[i] == 'T') dt++;
    }

    ll swap1 = min(xt, tx); xt -= swap1; tx -= swap1;
    ll swap2 = min(xd, dx); xd -= swap2; dx -= swap2;
    ll swap3 = min(td, dt); td -= swap3; dt -= swap3;

    cnt += swap1 + swap2 + swap3;

    cnt += 2 * (xt + tx + xd + dx + td + dt) / 3;

    cout << cnt;
}
