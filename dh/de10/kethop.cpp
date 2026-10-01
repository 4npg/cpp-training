# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "kethop"

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

int x, y, z;
int n, ret;
int a[N_];

void sub1 () {

	cin >> x >> y >> z;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n - 2; i++) 
		for (int j = i + 1; j < n - 1; j++) 
			for (int k = j + 1; k < n; k++) 
				maximize(ret, x * a[i] + y * a[j] + z * a[k]);

	cout << ret;

}

void sub2 () {

	cin >> x >> y >> z;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];

	sort(a, a + n, greater<int>());

	cout << a[0] * x + a[1] * y +  a[2] * z;

}

void sub3 () {

	cin >> x >> y >> z;
	cin >> n;

	long long dp1 = -inf;
	long long dp2 = -inf;
	long long dp3 = -inf;

	for (int i = 0; i < n; i++) {
		long long val; cin >> val;

		if (dp2 != -inf) dp3 = max(dp3, dp2 + z * val);
		if (dp1 != -inf) dp2 = max(dp2, dp1 + y * val);
		dp1 = max(dp1, x * val);
	}

	cout << dp3;

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    sub3();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


