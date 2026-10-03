# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

const int N_ = 1e3+5;
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

int m, r, u;
int v[N_], t[N_], f[N_];
int dp[N_][N_];
int ret;

void Try(int pos, int amount, int tim, int hapi) {
    if (amount > u || tim > m) return;
    if (pos > r) {
        maximize(ret, hapi);
        return;
    }

    Try(pos + 1, amount, tim, hapi);
    Try(pos + 1, amount + f[pos], tim + t[pos], hapi + v[pos]);   
}

void sub1() {

    cin >> m >> u >> r;
    
    for (int i = 1; i <= r; i++) {
        cin >> v[i] >> t[i] >> f[i];
    }

    Try(1, 0, 0, 0);

    cout << ret;
}

void sub2 () {
    cin >> m >> u >> r;

    for (int i = 1; i <= r; i++) {
        cin >> v[i] >> t[i] >> f[i];
    }

    dp[0][0] = 0;

    for (int i = 1; i <= r; i++)
        for (int am = u; am >= f[i]; am--) 
            for (int tim = m; tim >= t[i]; tim--) 
                maximize(dp[am][tim], dp[am - f[i]][tim - t[i]] + v[i]);

    cout << dp[u][m];
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    sub2();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


