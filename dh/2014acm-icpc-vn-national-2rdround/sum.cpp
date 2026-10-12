# include<bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ri(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

const int _N = 1e6+5;
const int mod = 1e6;
const int inf = 1e9;

template <typename T> bool minimize(T &a, const T &b) { if (a > b) return a = b, true; return false; }
template <typename T> bool maximize(T &a, const T &b) { if (a < b) return a = b, true; return false; }
template <typename T> T opw(T a, T b) { T ans = 1; while (b) { if (b&1) ans = (ans * a) % mod; a = (a * a) % mod; b >>=1; } return ans; }
template <typename T> int size32 (const T &a) { return (int)a.size(); }

int t;

void solve() {

	cin >> t;

	while (t--) {
		long long n; cin >> n; long long ret = 0;
		for (long long l = 1, r; l <= n; l = r + 1) {
			long long q = n / l;
			r = n / q;
			ret = (ret + (q % mod) * ((r - l + 1) % mod)) % mod;
		}
		cout << ret << '\n';
	}

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}

