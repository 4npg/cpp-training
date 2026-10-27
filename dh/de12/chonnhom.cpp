#include <bits/stdc++.h>
using namespace std;

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file "chonnhom"

const int N_ = 1005;
const int K_ = 1005;
const int MAXX = 50;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(T &a, T b) { if (a > b) return a = b, 1; return 0; }
template <typename T> bool maximize(T &a, T b) { if (a < b) return a = b, 1; return 0; }
template <typename T> T opw(T a, T b) { T ans = 1; while (b) { if (b&1) ans = (ans * a) % mod; a = (a * a) % mod; b >>=1; } return ans; }
template <typename T> int size32 (const T &a) { return (int)a.size(); }

template <typename T, int D>
struct Vec : public vector<Vec<T, D - 1>> {
    static_assert(D >= 1, "Error");
    template <typename ... Args>
    Vec (int n = 0, Args ... args) 
        : vector<Vec<T, D - 1>> (n, Vec<T, D - 1> (args ...)) {}
};

template <typename T> struct Vec<T, 1> : public vector<T> {
    Vec (int n = 0, const T &val = T()) : vector<T> (n, val) {}
};

mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int ri (int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int n, k;
string si[N_];

namespace sub1 {
    int ans = 0;
    int cnt[N_];
    int gid[N_];

    void Try(int pos, int cur) {
        if (cur > k) return;
        if (pos == n) {
            if (cur == k) ans = (ans + 1) % mod;
            return;
        }

        Try(pos + 1, cur);

        int g = gid[pos];
        cnt[g]++;

        Try(pos + 1, cur + cnt[g] - 1);
        cnt[g]--;
    }

    void sol() {
        
        map<string, int> mp;
        int m = 0;

        for (int i = 0; i < n; i++) {
            if (!mp.count(si[i])) mp[si[i]] = m++;
            gid[i] = mp[si[i]];
        }
        Try(0, 0);
        cout << ans;
    }
}


void solve() {

	cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> si[i];
        sort(si[i].begin(), si[i].end());
    }

    sub1::sol();
}

int32_t main (void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
