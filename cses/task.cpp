#include <algorithm>
#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "tchat"

const int N_ = 2e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template<class T> bool minimize(T a, T &b) { if (a > b) return a = b, true; return false; }
template<class T> bool maximize(T a, T &b) { if (a < b) return a = b, true; return false; }
template<class T> T opw(T a, T b) { T ans = 1; while (b) { if (b&1) ans = (ans * a) % mod; a = (a * a) % mod; b >>=1; } return ans; }

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ri(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

long long bit[N_];

int n;

long long t, ret;
vector<long long> values;
long long pre[N_];

inline void upd(int x, long long v) {

    for (; x <= n + 1; x += x & -x) bit[x] += v;

}

// template<typename T> inline T get(int x) {
    
//     T ret = 0;
//     for(; x >= 1; x &= (x - 1)) ret += bit[x];
//     return ret;

// }

long long get(int x) {
    long long ret = 0;
    for (; x >= 1; x &= (x - 1)) ret += bit[x];
    return ret;
}


void solve() {

    cin >> n >> t;

    values.emplace_back(pre[0]);

    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        pre[i] = pre[i-1] + x;

        values.emplace_back(pre[i]);
    }

    sort(values.begin(), values.end());
    values.resize(unique(values.begin(), values.end()) - values.begin());

    int pos = lower_bound(values.begin(), values.end(), pre[0]) - values.begin() + 1;

    upd(pos, 1);

    // cout << get(2) - get(1) << '\n';

    for (int r = 1; r <= n; r++) {
        long long x  = pre[r] - t;

        int p = upper_bound(values.begin(), values.end(), x) - values.begin();

        ret += get(values.size()) - get(p);

        pos = lower_bound(values.begin(), values.end(), pre[r]) - values.begin() + 1;

        upd(pos, 1);
    }

    cout << ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
