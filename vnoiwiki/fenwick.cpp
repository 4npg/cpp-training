#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int N_ = 1e5+5;
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

int n, q;
int a[N_];
long long bitadd[N_], bitmul[N_];

void upd(long long bit[], int x, long long v) {
    for (; x <= n; x += x & -x) bit[x] += v;
}

void updrange(int l, int r, long long v) {
    upd(bitmul, l, v);
    upd(bitmul, r + 1, -v);

    upd(bitadd, l, -v * (l - 1));
    upd(bitadd, r + 1, v * r);
}


long long getbit(long long bit[], long long x) {
    long long ret = 0;

    for (; x >= 1; x &= x - 1) ret += bit[x];

    return ret;
}

long long getprefix(int x) {
    return getbit(bitmul, x) * x + getbit(bitadd, x);
}

void solve() {
    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        updrange(i, i, a[i]);
    }

    while (q--) {
        int op;
        cin >> op; if (op == 1) {
            int u, v; long long x;
            cin >> u >> v >> x;
            updrange(u, v, x);
        } else {
            int u, v; cin >> u >> v;
            cout << getprefix(v) - getprefix(u - 1) << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
