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

int n;
int a[N_]; int x, y; int fib[N_];
int fibsz = 0;
int mxfib = 0;
int ret = 0;

bool check (int val) {
    if (val > mxfib || val < fib[0]) return false;
    int l = 0, r = fibsz - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (fib[mid] == val) return true;
        if (fib[mid] < val) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

void Try (int pos) {
    if (pos > n) {
        ret++;
        return;
    }

    int cur_sum = 0;
    for (int j = pos; j <= n; j++) {
        cur_sum += a[j];

        if (cur_sum > mxfib) break;

        if (check(cur_sum)) Try(j + 1);
    }
}

void solve() {

	cin >> n; int total = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], total += a[i];
	cin >> x >> y;
    
    fib[fibsz++] = x;
    if (y <= total && y != x) {
        fib[fibsz++] = y;
    }

    int f1 = x, f2 = y;
    while (f1 <= total - f2) {
        int f3 = f1 + f2;
        fib[fibsz++] = f3;
        f1 = f2;
        f2 = f3;
    }

    sort(fib, fib + fibsz);

    fibsz = unique(fib, fib + fibsz) - fib;
    mxfib = fib[fibsz - 1];

    Try(1); cout << ret;
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


