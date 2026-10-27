# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "dieukhien"

const int M_ = 5010;
const int N_ = 30;
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


namespace sub1 {

	int m, n, s;		
	int c[M_][N_];
	int count_zero = 0;

	void upd_row (int r) {
		for (int co = 1; co <= n; co++) {
			if (c[r][co] == 0) {
				count_zero--;
				c[r][co] = 1;
			} else if (c[r][co] == 1) {
				c[r][co]++;
			} else if (c[r][co] == 2) {
				c[r][co] = 0;
				count_zero++;
			}
		}
	}

	void upd_col (int col) {
		for (int ro = 1; ro <= m; ro++) {
			if (c[ro][col] == 0) {
				count_zero--;
				c[ro][col] = 1;
			} else if (c[ro][col] == 1) {
				c[ro][col]++;
			} else if (c[ro][col] == 2) {
				c[ro][col] = 0;
				count_zero++;
			}
		}
	}

	void solve() {

		cin >> m >> n >> s;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> c[i][j];
				if (c[i][j] == 0) count_zero++;
			}
		}

		while (s--) {

			int op; cin >> op;

			if (op >= 1 && op <= n) {
				upd_row(op);
			} else upd_col(op - m);

		}

		cout << count_zero;
	}

}

namespace sub2 {

	int m, n, s;
	int c[M_][N_];
	int R[M_], C[N_];
	int count_zero = 0;

	void solve () {
		cin >> m >> n >> s;
		for (int i = 1; i <= m; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> c[i][j];
			}
		}

		while (s--) {
			int op; cin >> op;

			if (op >= 1 && op <= m) { 
				R[op] = (R[op] + 1) % 3;
			} else {
				int col = op - m;
				C[col] = (C[col] + 1) % 3;
			}
		}

		for (int i = 1; i <= m; i++) {
			int r = R[i];
			for (int j = 1; j <= n; j++) {
				if ((c[i][j] + r + C[j])  % 3 == 0) count_zero++;
			}
		}

		cout << count_zero;
	}
	
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    sub2::solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


