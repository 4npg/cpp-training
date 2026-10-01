# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "nguyento"

const int maxn = (int)1e6 + 5;
const int N_ = 16000005;
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

long long pre[N_];
int t;
bitset<N_> d; vector <int> p;

void sang() {

	d[0] = d[1] = 1;
	for (int i = 2; i * i < N_; i++) 
		if (!d[i]) for (int j = i * i; j < N_; j += i) d[j] = 1;
	
	p.emplace_back(0);
	for (int i = 2; i < N_; i++) if (!d[i]) p.emplace_back(i);

}

int n;

void solve() {

	sang();

	cin >> t;

	// p.erase(unique(p.begin(), p.end()), p.end());
	pre[0] = 0;
	for (int i = 1; i <= maxn; i++) pre[i] = pre[i - 1] + p[i] * 1LL;

	// for (int i = 1; i <= maxn; i++) cout << pre[i] << ' ';
	while (t--) {
		// int n; n = ri(5e5, 1e6);
		int n; cin >> n;
		// cerr << n << '\n';
		cout << pre[n] << '\n';
	}

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


