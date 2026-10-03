# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

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

int n, k, s;
vector < pair<int, int> > dta;
int ret; int num;

void Try(int pos, int dvs, int wght, int cost) {
	if (cost < 0) return ;
	if (pos == n) {
		if (dvs > 0 && dvs % k == 0) {
			maximize(ret, wght);
		}
		return;
	}

	Try(pos + 1, dvs, wght, cost);
	if (cost >= dta[pos].second) {
		Try(pos + 1, dvs + 1, wght + dta[pos].first, cost - dta[pos].second);
	}
}
void solve() {

	cin >> n >> k >> s;
	dta.resize(n);

	for (int i = 0; i < n; i++) {
		cin >> dta[i].first;
	} 
	for (int i = 0; i < n; i++) {
		cin >> dta[i].second;
	}

	Try(0, 0, 0, s);
	cout << ret;
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


