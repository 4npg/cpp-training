# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "trochoi"

const int N_ = 1e3+5;
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

mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int ri (int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int m, n;

// Vec<int, 2> sorta (const vector< vector<int> > &a, int n, int m) {
// 	vector<int> od;
// 	od.reserve(n * m);
// 	for (int i = 0; i < n; i++) 
// 		for (int j = 0; j < m; j++) 
// 			od.emplace_back(a[i][j]);

// 	sort(od.begin(), od.end());


// 	Vec<int, 2> ret(n, m);

// 	for (int i = 0; i < n; i++) {
// 		for (int j = 0; j < m; j++) {
// 			int col = (i % 2 == 0) ? j : (m - 1 - j);
// 			ret[i][col] = od[i * m + j];
// 		}
// 	}

// 	return ret;
// }

int od[N_];

void solve() {

	cin >> n >> m ;

	// vector< vector <int> > a(n, vector<int>(m));

	// for (int i = 0 ; i < n; i++) 
	// 	for (int j = 0; j < m; j++) 
	// 		cin >> a[i][j];
	// vector <int> od(n * m);
	for (int i = 0; i < n * m; i++) cin >> od[i];
	// od.reserve(n * m);
	// for (int i = 0; i < n; i++) 
	// 	for (int j = 0; j < m; j++) 
	// 		od.emplace_back(a[i][j]);

	// sort(od.begin(), od.end());

	sort(od, od + n * m);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int col = (i % 2 == 0) ? j : (m - 1 - j);
			cout << od[i * m + col] << ' ';
		}
		cout << '\n';
	}


	// auto ret = sorta(a, n, m);

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) 
	// 		cout << ret[i][j] << ' ';
	// 	cout << '\n';
	// }
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


