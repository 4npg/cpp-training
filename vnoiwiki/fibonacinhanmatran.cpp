#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout << "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

const ll MOD = 1000000007;

vector<vector<ll>> mul(const vector<vector<ll>> &a, const vector<vector<ll>> &b) {
    vector<vector<ll>> c(2, vector<ll>(2));
    FOR(i, 0, 1) {
        FOR(j, 0, 1) {
            FOR(k, 0, 1) {
                c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
            }
        }
    }
    return c;
}

vector<vector<ll>> ipow(vector<vector<ll>> a, ll b) {
    vector<vector<ll>> res = {{1, 0}, {0, 1}};
    while (b) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    vector<vector<ll>> A = {{1, 1}, {1, 0}};
    ll t; cin>>t;
    while(t--){
        ll n;
        cin >> n;
        if (n == 0) {
            cout << 0;
            return 0;
        }

        vector<vector<ll>> An = ipow(A, n);
        cout << An[0][0];
       
        nl;
    }
}
