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

bool isPrime(int64 n);

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

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

int64 f(int64 x, int64 c, int64 mod) {
    return (mulmod(x, x, mod) + c) % mod;
}

int64 pollard_rho(int64 n) {
    if (n % 2 == 0) return 2;
    if (isPrime(n)) return n;

    while (true) {
        int64 x = rng() % n;
        int64 y = x;
        int64 c = rng() % n;
        if (c == 0) c++;

        int64 d = 1;
        while (d == 1) {
            x = f(x, c, n);
            y = f(f(y, c, n), c, n);
            d = gcd(abs(x - y), n);
        }
        if (d != n) return d;
    }
}

vector<int64> factorize(int64 n) {
    if (n == 1) return {};
    if (isPrime(n)) return {n};
    int64 d = pollard_rho(n);
    auto a = factorize(d);
    auto b = factorize(n / d);
    a.insert(a.end(), b.begin(), b.end());
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<int64> f = factorize(n);
    sort(f.begin(), f.end());
    for (auto x: f) cout << x << " ";
}
