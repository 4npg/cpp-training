#include <bits/stdc++.h>
using namespace std;
#define ll long long
using namespace std;
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)

const ll MAX = 1e6 + 5;
const ll MOD = 1e9 + 7;

ll dp[MAX];
ll giaiThua[MAX], nghichDaoGT[MAX];
ll n;

ll pow(ll a, ll b) {
    ll kq = 1;
    while (b) {
        if (b & 1) kq = kq * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return kq;
}

void xuli() {
    giaiThua[0] = nghichDaoGT[0] = 1;
    for (ll i = 1; i < MAX; ++i) {
        giaiThua[i] = giaiThua[i - 1] * i % MOD;
        nghichDaoGT[i] = pow(giaiThua[i], MOD - 2);
    }
}

ll toHop(ll a, ll b) {
    if (b < 0 || b > a) return 0;
    return giaiThua[a] * nghichDaoGT[b] % MOD * nghichDaoGT[a - b] % MOD;
}

void sub1() {
    dp[1] = 1;
    for (ll i = 1; i <= n; ++i) {
        for (ll j = 1; j <= n; ++j) {
            if (j > 1) dp[j] = (dp[j] + dp[j - 1]) % MOD;
        }
    }
    cout << dp[n];
}

void sub2() {
    cout << toHop(2 * n - 2, n - 1);
}
void READFILE(){
    freopen("DUONGDI.INP","r",stdin);
    freopen("DUONGDI.OUT","w",stdout);
}
int main() {
    fast;READFILE();
    cin >> n;
    xuli();
    if (n <= 10) sub1();
    else sub2();
}
