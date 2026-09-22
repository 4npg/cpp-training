# include<bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "bobaso"

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
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

mt19937_64 rd (chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int ri (int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl (long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

int n;
int a[N_];
int mx = -inf;

void trau() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				mx = max(mx, a[i] + 2 * a[j] + 3 * a[k]);
			}
		}
	}

	cout << mx;

}

int suff[N_];

void solve() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	suff[n - 1] = a[n - 1];
	for (int k = n - 2; ~k; k--) {
		suff[k] = max(suff[k + 1], a[k]);
	}

	int ret = -inf; int pref = a[0];

	for (int j = 1; j < n - 1; j++) {
		ret = max(ret, pref + 2 * a[j] + 3 * suff[j + 1]);
		maximize(pref, a[j]);
	}

	cout << ret;
}

int dp1 = -inf;
int dp2 = -inf;
int dp3 = -inf;

void soldp() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (dp2 != -inf) dp3 = max(dp3, dp2 + 3 * x);
		if (dp1 != -inf) dp2 = max(dp2, dp1 + 2 * x);
		dp1 = max(dp1, x);
	}
	
	cout << dp3;
}

int main (void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    soldp();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}


