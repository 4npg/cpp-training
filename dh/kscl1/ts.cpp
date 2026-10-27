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

int n, k, u, v, l, r;

inline void print (const vector < int > &a) {
    for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    cout << '\n';
}

namespace sub1 {

    void solve() {

        cin >> n >> k >> u >> v >> l >> r;
        vector < int > a (n);
        iota(a.begin(), a.end(), 1);

        while (k--) {

            for (int i = u - 1; i <= (v - 1) / 2; i++) {
                int tmp = a[i];
                a[i] = a[v - i + u - 2];
                a[v - i + u - 2] = tmp;
            }

            for (int i = l - 1; i <= (r - 1) / 2; i++ ) {
                int tmp = a[i];
                a[i] = a[r - i + l - 2];
                a[r - i + l - 2] = tmp;
            }
        }

        for (auto &x : a) cout << x << '\n';
    }

}

void solve() {

    cin >> n >> k >> u >> v >> l >> r;
    vector < int > a (n + 1);
    for (int i = 1; i <= n; i++) a[i] = i;

    while (k--) {
        reverse(a.begin() + u, a.begin() + v + 1);
        reverse(a.begin() + l, a.begin() + r + 1);
    }

    print(a);
    // print(a);
    // reverse(a.begin() + u, a.begin() + v + 1);
    // // print(a);
    // reverse(a.begin() + l, a.begin() + r + 1);
    // print(a);

    // vector < int > ans (n + 1);
    // vector < bool > vis (n + 1, 0);

    // for (int i = 1; i <= n; i++) {
    //  if (!vis[i]) {
    //      vector <int > cycle; int cur = i;
    //      while (!vis[cur]) {
    //          vis[cur] = true; cycle.emplace_back(cur);
    //          cur = a[cur];
    //      }

    //      int L = size32(cycle); int dich = k % L;

    //      for (int j = 0; j < L; j++) {
    //          ans[cycle[j]] = cycle[(j + dich) % L];
    //      }
    //  }
    // }

    // cout << '\n';


    // for (int i = 1; i <= n; i++) {
    //  cout << ans[i] << (i == n ? ' ' : '\n');
    // }

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    sub1::solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


