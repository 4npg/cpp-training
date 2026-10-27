# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "nguyento"

const int N_ = 1e6+5;
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


long long n;

namespace sub1 {

	bitset <N_> d; vector < long long > almost_primes;

	void sang () {

		d[0] = d[1] = 1;
		for (int i = 2; i * i < N_; i ++) if (!d[i]) {
			for (int j = i * i; j < N_; j += i) d[j] = 1;
		}

		for (int i = 2; i  < N_; i++) if (!d[i]) almost_primes.emplace_back(i * i * 1LL);
	}

	void solve() {
		sang();

		cin >> n;
		for (auto &x : almost_primes) if (x >= n) {
			cout << x; break;
		}
	}

}

namespace sub2 {


	bool nto (long long n) {
		if (n < 2) return false;
		if (n == 2 || n == 3) return true;
		if (n % 2 == 0 || n % 3 == 0) return false;

		for (long long i = 5; i * i <= n; i += 6) {
			if (n % i == 0 || n % (i + 2) == 0) return false;
		}
		return true;
	}

	bool check (long long mid, long long n) {
		return mid * mid >= n;
	}

	void solve () {
		cin >> n;

		long long l = 0, r = 2000000000LL;
		long long ans;

		while (l <= r) {
			long long mid = l + (r - l) / 2;
			if (check (mid, n)) {
				ans = mid; r = mid - 1;
			} else l = mid + 1;
		}
		if (ans < 2) ans = 2;
		while (!nto(ans)) ans ++;

		cout << ans * ans;
	}
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    sub2::solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


