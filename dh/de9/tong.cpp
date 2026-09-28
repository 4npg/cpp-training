# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "tong"

const int N_ = 1e5+5;
const int mod = 1e9 + 7;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(T a, T &b) { if (a > b) return a = b, 1; return 0; }
template <typename T> bool maximize(T a, T &b) { if (a < b) return a = b, 1; return 0; }
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
long long k, p;
long long a[N_], pre[N_];

void solve() {

	cin >> n >> k >> p; pre[0] = 0;
	for (int i = 1; i <= n; i++) cin >> a[i], pre[i] = (pre[i - 1] + (a[i] % mod + mod)) % mod;

	long long st = ((p - 1) % n) + 1;
	long long fl = k / n; long long du = k % n;

	long long ret = ((fl % mod) * pre[n]) % mod;
	if (du > 0) {
		if (st + du - 1 <= n) {
			ret = (ret + pre[st + du - 1] - pre[st - 1] + mod) % mod;
		} else {
			ret = (ret + pre[n] - pre[st - 1]) % mod;
			long long lo = du - (n - st + 1);
			ret = (ret + pre[lo]) % mod;
		}
	}

	cout << ret % mod;
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


