# include<bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "CAU4"

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(T a, const T &b) { if (a > b) return a = b, 1; return 0; }
template <typename T> bool maximize(T a, const T &b) { if (a < b) return a = b, 1; return 0; }
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

string a, b, c;
int t;
int n, m;
int ans = 1e9;

void Try (int i, int j, int diff) {
	if (diff > ans) return;

	if (i == n && j == m) {
		ans = min(ans, diff);
		return ;
	}

	int c_idx = i + j;
	if (i < n) {
		int cost = (a[i] != c[c_idx]);
		Try(i + 1, j, diff + cost);
	}

	if (j < m) {
		int cost = (b[j] != c[c_idx]);
		Try(i, j + 1, diff + cost);
	}
}

void solve() {

	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		ans = 1e9; n = a.size(), m = b.size();
		Try(0, 0, 0);

		cout << ans << '\n';
	}
}

void solve_dp() {

	cin >> t;
	while (t--) {
		cin >> a >> b >> c;
		n = a.size(); m = b.size();
		a = ' ' + a;
		b = ' ' + b;
		c = ' ' + c;

		Vec<int, 2> dp(n + 1, m + 1, inf);
		// vector< vector<int> > dp(n + 1, vector <int> (m + 1, 0x3f));
		dp[0][0] = 0;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				if (i == 0 && j == 0) continue;
				int c_idx = i + j;
				if (i > 0) {
					int cost = (a[i] != c[c_idx]);
					dp[i][j] = min(dp[i][j], dp[i-1][j] + cost);
				}

				if (j > 0) {
					int cost = (b[j] != c[c_idx]);
					dp[i][j] = min(dp[i][j], dp[i][j-1] + cost);
				}
			}
		}

		cout << dp[n][m] << '\n';
	}
}

int main (void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve_dp();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}


