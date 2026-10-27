# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "cotchan"

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(const T &a, T b) { if (a > b) return a = b, 1; return 0; }
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

int n; long long k;
long long x[N_];

bool check (long long q) {
	long long placed = 0;
	for (int i = 0; i < n - 1; i++) {
		long long d= x[i + 1] - x[i];
		placed += (d - 1) / q;

		if (placed > k) return 0;
	}
	return placed <= k;
}

void solve() {

	cin >> n >> k;
	for (int i = 0; i < n; i++) cin >> x[i];

	// n = ri(10, 12);
	// k = ri(5, 10);

	// cerr << n << ' ' << k << '\n';

	// x[0] = 1;

	// for (int i = 1; i < n; i++) {
	// 	x[i] = ri(x[i - 1] + 1, 100);
	// 	cerr << x[i] << ' ';
	// }

	sort(x, x + n);

	long long l = 1, r = 0;
	for (int i = 0; i < n - 1; i++) r = max(r, 1ll * (x[i + 1] - x[i]));

	long long ans = r;
	while (l <= r) {
		long long mid = l + (r - l) / 2;
		if (check(mid)) {
			ans = mid; r = mid - 1;
		} else l = mid + 1;
	}

	cout << ans;
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


