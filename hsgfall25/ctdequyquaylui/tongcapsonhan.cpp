// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

int64 a,n,mod;

int64 mul(int64 a,int64 b,int64 mod){
    a %= mod;
    int64 ans = 0;
    while (b) {
        if (b & 1) {
            ans += a;
            if (ans >= mod) ans -= mod;
        }
        a += a;
        if (a >= mod) a -= mod;
        b >>= 1;
    }
    return ans % mod;
}

int64 ipow(int64 a,int64 b,int64 mod){
    int64 ans = 1 % mod;
    a %= mod;
    while (b) {
        if (b & 1) ans = mul(ans, a, mod);
        a = mul(a, a, mod);
        b >>= 1;
    }
    return ans;
}

int64 sumpow(int64 a,int64 b,int64 mod){
    if (mod == 1) return 0;
    if (b == 0) return 1 % mod;
    if (b & 1) {
        int64 k = b / 2;
        int64 s = sumpow(a, k, mod);
        int64 p = ipow(a, k + 1, mod);
        int64 t = (1 + p) % mod;
        return mul(s, t, mod);
    } else {
        int64 k = b / 2;
        int64 s = (k - 1 >= 0) ? sumpow(a, k - 1, mod) : 0;
        int64 p = ipow(a, k + 1, mod);
        int64 ak = ipow(a, k, mod);
        int64 t = mul(s, (1 + p) % mod, mod);
        t += ak;
        if (t >= mod) t -= mod;
        return t;
    }
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    if (!(cin >> a >> n >> mod)) return 0;
    cout << sumpow(a, n, mod);
}
