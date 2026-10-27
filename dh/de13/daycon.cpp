# include <bits/stdc++.h>
#include <cstdint>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "daycon"

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

namespace sub1 {
	int n, m;
	int ret;
	int pref[N_];

	void solve() {

		// cin >> n >> m;
		n = ri (10, 12);
		m = ri (15, 20);
		cerr  << n << ' ' << m << '\n';

		for (int i = 1; i <= n; i++) {
			// int x; cin >> x;
			int x; x = ri (1, 21);
			cerr << x << ' ' ;
			pref[i] = pref[i - 1] + x;
		}

		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (pref[j] - pref[i - 1] <= m) ret++;
			}
		}

		cout << ret;
	}
}

namespace sub2 {
	int n, m; int a[N_];
	int ret, pref = 0;
	int l = 1;

	void solve () {

		cin >> n >> m;
		for (int i = 1; i <= n; i++) {
			cin >> a[i];
		}

		for (int r = 1; r <= n; r++) {
			pref += a[r];

			while (l <= r && pref > m) {
				pref -= a[l];
				l++;
			}

			ret += (r - l + 1);
		}

		cout << ret;
	}
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    sub2::solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


