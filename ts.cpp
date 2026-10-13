# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
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

# define LOG 19 
# define MASK(i) (1LL << i)

int n, s, l;
int a[N_], minV[N_][LOG + 1], maxV[N_][LOG + 1];

inline int getMin(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return min(minV[l][k], minV[r - MASK(k) + 1][k]);
}

inline int getMax(int l, int r) {
    int k = 31 - __builtin_clz(r - l + 1);
    return max(maxV[l][k], maxV[r - MASK(k) + 1][k]);
}

struct seg {

    int n;
    vector < long long > t;

    seg(int _n) : n(_n), t(_n * 4, inf) {};

    // void build (int id, int l, int r) {
    //     if (l == r) {
    //         t[id] = a[l];
    //         return;
    //     }

    //     int mid = (l + r) / 2;
    //     build(id * 2, l, mid);
    //     build(id * 2 + 1, mid + 1, r);
    //     t[id] = min(t[id * 2], t[id * 2 + 1]);
    // }

    inline void update (int id, int l, int r, int p, long long x) {
        if (l == r) {
            t[id] = x;
            return;
        }

        int mid = (l + r) / 2;
        if (p <= mid) update(id * 2, l, mid, p, x);
        else update(id * 2 + 1, mid + 1, r, p, x);

        t[id] = min(t[id * 2], t[id * 2 + 1]);
    }

    inline long long get (int id, int l, int r, int u, int v) {
        if (v < l || r < u) return inf;
        if (u <= l && r <= v) return t[id];

        int mid = (l + r) / 2;

        long long tl = get(id * 2, l, mid, u, v);
        long long tr = get(id * 2 + 1, mid + 1, r, u, v);

        return min(tl, tr);
    }

    void update(int p, int x) {
        update(1, 0, n, p, x);
    }

    long long get(int l, int r) {
        if (l > r) return inf;
        return get(1, 0, n, l, r);
    }
};

void solve() {

    cin >> n >> s >> l;
    for (int i = 1; i <= n; i++) cin >> a[i];

    for (int i = 1; i <= n; i++) minV[i][0] = a[i], maxV[i][0] = a[i];

    for (int j = 1; j <= LOG; j++) 
        for (int i = 1; i <= n - MASK(j) + 1; i++)
            minV[i][j] = min(minV[i][j - 1], minV[i + MASK(j - 1)][j - 1]),
            maxV[i][j] = max(maxV[i][j - 1], maxV[i + MASK(j - 1)][j - 1]);

    vector < long long > L(n + 1);
    for (int i = 1; i <= n; i++) {
        int lo = 1, hi = i;
        while (lo < hi) {
            int mid = (lo + hi) / 2;
            if (getMax(mid, i) - getMin(mid, i) <= s) hi = mid;
            else lo = mid + 1;
        }
        L[i] = lo;
    }

    vector < long long > dp(n + 1, inf);
    dp[0] = 0;

    seg st(n);
    st.update(0, dp[0]);

    for (int i = 1; i <= n; i++) {
        int lo = 1, hi = i;

        while (lo < hi) {
            int mid = (lo + hi) / 2;

            if (getMax(mid, i) - getMin(mid, i) <= s) hi = mid;
            else lo = mid + 1;

        }

        if (i >= l) {
            int j = st.get(lo - 1, i - l);

            if (j < inf) dp[i] = j + 1;
        }

        st.update(i, dp[i]);
    }

    cout << (dp[n] == inf ? -1 : dp[n]);

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


