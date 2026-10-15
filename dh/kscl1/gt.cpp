# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "gt"

const int N_ = 1005;
const int mod = 1e9 + 7;
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

int n, k;

namespace sub1 {
	int fac (int n) {
		int ret = 1;
		while (n != 1) {
			ret = ret * n;
			n = n - 1;
		}
		return ret;
	}

	long long cnt = 0;

	int multiple(vector < int > &a) {
		int ret = 1;
		for (auto & v : a) {
			ret *= v;
		}
		return ret;
	}

	vector < int > cur;

	void print() {
		for (auto &v: cur) cout << v << ' ' ;
		cout << '\n';
	}

	void Try(int pos) {
		if (pos == k) {
			cnt = (cnt % mod +  1LL * (multiple(cur) == n) % mod) % mod;
			// if (multiple(cur) == n) print();
			return;
		}

		for (int i = 1; i <= n; i++) {
			cur.emplace_back(i);
			Try(pos + 1);
			cur.pop_back();
		}


	}

	void solve() {

		cin >> n >> k;
		n = fac(n); 
		// cout << n << '\n';
		Try(0);

		cout << cnt;
	}

}

namespace sub2 {
	int dp[N_][N_];

	int ge (int n, int p) {
		int cnt = 0;
		while (n >= p) {
			cnt += n / p;
			n /= p;
		}
		return cnt;
	}

	void init (int max_k, int max_a) {
		for (int j = 0; j <= max_a; j++) {
			dp[1][j] = 1;
		}

		for (int i = 1; i <= max_k; i++) {
			dp[i][0] = 1;
		}

		for (int i = 2; i <= max_k; i++) {
			for (int j = 1; j <= max_a; j++) {
				dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
			}
		}
	}

	bitset<N_> d;
	vector < int > p;

	void sang () {	
		d[0] = d[1] = 1;
		for (int i = 2; i * i < N_; i++) 
			if (!d[i]) for (int j = i * i; j < N_; j += i) d[j] = 1;

		for (int i = 2; i < N_; i++) if (!d[i]) p.emplace_back(i);
	}

	void solve () {

		sang();

		cin >> n >> k;
		if (k == 0) {
			cout << (n <= 1 ? 1 : 0);
			return;
		}

		if (n <= 1) {
			cout << 1 << '\n';
			return;
		}

		init(k, n);
		long long cnt = 1;
		for (auto &pr : p) {
			int al = ge(n, pr);
			cnt = (cnt * dp[k][al]) % mod;
		}

		cout << cnt;
	}

}


int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    // sub1::solve();
    
    // cout << '\n';

    sub2::solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


