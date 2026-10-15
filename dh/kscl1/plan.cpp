# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "plan"

const int N_ = 1020;
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

int n, m, q, h, w;
long long diff[N_][N_];
long long pref[N_][N_];

void upd (int r1, int c1, int r2, int c2, long long v) {
	diff[r1][c1] += v;
	diff[r1][c2 + 1] -= v;
	diff[r2 + 1][c1] -= v;
	diff[r2 + 1][c2 + 1] += v;
}

void print () {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << diff[i][j] << ' ';
		}
		cout << '\n';
	}
	cout << '\n';
}

void solve() {

	cin >> n >> m >> q;

	while (q--) {
		int r1, c1, r2, c2;
		long long v;
		cin >> r1 >> c1 >> r2 >> c2 >> v;
		upd(r1, c1, r2, c2, v);
		// print();
	}

	cin >> h >> w;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			diff[i][j] += diff[i - 1][j] + diff[i][j - 1] - diff[i - 1][j - 1];

			// print();
		}
	}

	// print();

	// return;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + diff[i][j];
		}
	}

	long long ret = -inf;
	for (int i = w; i <= n; i++) {
		for (int j = h; j <= m; j++) {
			// long long cur = pref[i][j] - pref[i - w][j] - pref[i][j - h] + pref[i - w][j - h];
			// if (cur > ret) ret = cur;
			maximize(ret, pref[i][j] - pref[i - w][j] - pref[i][j - h] + pref[i - w][j - h]);
		}
	}

	cout << ret;

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


