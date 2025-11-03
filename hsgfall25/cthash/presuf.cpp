// author : anphung
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file "presuf"

const int64 base = 131;
const int64 mod1 = 1000000007;
const int64 mod2 = 1000000009;

pair<int64,int64> getHash(int l, int r,
                          const vector<int64> &h1, const vector<int64> &h2,
                          const vector<int64> &pw1, const vector<int64> &pw2) {
    int64 x1 = (h1[r] - h1[l-1] * pw1[r-l+1]) % mod1;
    int64 x2 = (h2[r] - h2[l-1] * pw2[r-l+1]) % mod2;
    if (x1 < 0) x1 += mod1;
    if (x2 < 0) x2 += mod2;
    return {x1, x2};
}

int32_t main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    string s, t;
    cin>>s>>t;
    int n = s.size(), m = t.size();

    vector<int64> pw1(max(n, m) + 5, 1), pw2(max(n, m) + 5, 1);
    f0(i, 1, max(n, m)) {
        pw1[i] = pw1[i-1] * base % mod1;
        pw2[i] = pw2[i-1] * base % mod2;
    }

    vector<int64> hs1(n + 1, 0), hs2(n + 1, 0);
    vector<int64> pwS1(m + 1, 0), pwS2(m + 1, 0);

    f0(i, 1, n) {
        hs1[i] = (hs1[i-1] * base + (s[i-1] - 'a' + 1)) % mod1;
        hs2[i] = (hs2[i-1] * base + (s[i-1] - 'a' + 1)) % mod2;
    }

    f0(i, 1, m) {
        pwS1[i] = (pwS1[i-1] * base + (t[i-1] - 'a' + 1)) % mod1;
        pwS2[i] = (pwS2[i-1] * base + (t[i-1] - 'a' + 1)) % mod2;
    }

    int overlap = 0;
    int lim = min(n, m);
    for (int k = lim; k >= 1; --k) {
        auto hs = getHash(n - k + 1, n, hs1, hs2, pw1, pw2);
        auto ht = getHash(1, k, pwS1, pwS2, pw1, pw2);
        if (hs == ht) {
            overlap = k;
            break;
        }
    }

    cout << s + t.substr(overlap) << "\n";
    cerr << "time elapsed: " << TIME << "s.\n";
}
