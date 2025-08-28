#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define pb push_back
#define fi first
#define se second
const int mod = 1e9 + 7;
const int maxn = 1e5+5;

vector<int> nto;
bitset<maxn>d;

void sang() {
    d[0] = d[1] = true;
    for (int i = 2; i * i < maxn; i++) {
        if (!d[i]) {
            for (int j = i * i; j < maxn; j += i)
                d[j] = true;
        }
    }
    for (int i = 2; i < maxn; i++)
        if (!d[i])
            nto.pb(i);
}

int64 ipow(int64 a, int64 b) {
    int64 res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}


vector<pair<int,int>> ptich(int x) {
    vector<pair<int,int>> res;
    for (int p : nto) {
        if (1LL * p * p > x) break;
        if (x % p == 0) {
            int cnt = 0;
            while (x % p == 0) { x /= p; cnt++; }
            res.pb({p, cnt});
        }
    }
    if (x > 1) res.pb({x, 1});
    return res;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);

    sang();

    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<unordered_map<int,int>> expnto(n); // lưu số mũ của mỗi prime trong a[i]
    unordered_map<int,int> mxexp; // lưu số mũ lớn nhất của mỗi prime trong toàn mảng

    int64 ans = 1;

    for (int i = 0; i < n; i++) {
        if(a[i]>1){
            cout<<"num = "<<a[i]<<" = ";
            auto fs = ptich(a[i]);
            for (auto &p : fs) {
                int64 tsnt = p.fi;
                int64 e = p.se;
                expnto[i][tsnt] = e;
                cout<<tsnt<<"^"<<e<<'\n';
                if (e > mxexp[tsnt]) {
                    ans = ans * ipow(tsnt, e - mxexp[tsnt]) % mod;
                    mxexp[tsnt] = e;
                }
            }
        }
    }

    // while (q--) {
    //     int i, x;
    //     cin >> i >> x;
    //     i--;

    //     auto fs = ptich(x);
    //     for (auto &p : fs) {
    //         int64 tsnt = p.fi;
    //         int64 e = p.se;
    //         int newExp = expnto[i][tsnt] + e;
    //         expnto[i][tsnt] = newExp;
    //         if (newExp > mxexp[tsnt]) {
    //             ans = ans * ipow(tsnt, newExp - mxexp[tsnt]) % mod;
    //             mxexp[tsnt] = newExp;
    //         }
    //     }
    //     cout << ans << "\n";
    // }
}
