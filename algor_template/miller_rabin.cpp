#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
using u128 = __uint128_t;

int64 mulmod(int64 a, int64 b, int64 mod) {
    return (u128)a * b % mod;
}

int64 binpow(int64 a, int64 d, int64 mod) {
    int64 r = 1;
    while (d) {
        if (d & 1) r = mulmod(r, a, mod);
        a = mulmod(a, a, mod);
        d >>= 1;
    }
    return r;
}

bool check(int64 n, int64 a, int64 d, int64 s) {
    int64 x = binpow(a, d, n);
    if (x == 1 || x == n - 1) return true;
    for (int i = 1; i < s; i++) {
        x = mulmod(x, x, n);
        if (x == n - 1) return true;
    }
    return false;
}

bool isPrime(int64 n) {
    if (n < 2) return false;
    for (int64 p: {2,3,5,7,11,13,17,19,23,29,31,37})
        if (n % p == 0) return n == p;

    int64 d = n - 1, s = 0;
    while ((d & 1) == 0) d >>= 1, s++;

    for (int64 a: {2,3,5,7,11,13,17})
        if (!check(n, a, d, s)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    cin >> x;
    cout << (isPrime(x) ? "YES" : "NO");
}
