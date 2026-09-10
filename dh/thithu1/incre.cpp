#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "incre"

const int N_ = 1e3+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(T a, T &b) { if (a > b) return a = b, true; return false; }
template <typename T> bool maximize(T a, T &b) { if (a < b) return a = b, true; return false; }
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

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ri(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

int n;
int a[N_];
long long ret;

int cnt[N_];


bool valid(int l, int r, const vector<int> &a, int mx) {

	vector<int> cnt(mx + 1, 0);

	for (int i = l; i <= r; i++) {
		if (a[i] > mx || a[i] < 1) return 0;
		cnt[a[i]]++;
	}

	for (int v = 1; v <= mx; v++) {
		if (cnt[v] != v) return 0;
	}
	return 1;
}

void solve() {

	cin >> n;
	vector<int> a(n + 1);

	for (int i = 1; i <= n; i++) cin >> a[i];

	for (int l = 1; l <= n; l++) {
		int mx = 0;
		long long cursum = 0;
		for (int r = l; r <= n; r++) {
			cursum += a[r];
			// maximize(mx, a[r]);

			mx = max(mx, a[r]);

			int len = r - l + 1;

			if (1LL * mx * (mx + 1) / 2 == len) {
				if (valid(l, r, a, mx)) ret += cursum;
			}
		}
	}

	cout << ret;
}



int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    // trau();
    // cout << '\n';
    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}

