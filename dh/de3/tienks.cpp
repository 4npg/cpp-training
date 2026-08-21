#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "tienks"

const int N_ = 12500;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template<class T> bool minimize(T a, T &b) { if (a > b) return a = b, true; false; }
template<class T> bool maximize(T a, T &b) { if (a < b) return a = b, true; false; }
template<class T> T opw(T a, T b) { T ans = 1; while (b) { if (b&1) ans = (ans * a) % mod; a = (a * a) % mod; b >>=1; } return ans; }

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ri(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

int n;

struct ks {
	int vao, ra, tien;

	bool cmp (ks &a, ks &b) {
		return a.ra < b.ra;
	}

	bool operator < (const ks & other) const {
		return ra < other.ra;
	}
};

long long dp[N_];

vector<ks> a(N_);
vector<int> x(N_);

void solve() {

	cin >> n;

	for (int i = 1; i <= n; i++) {

		cin >> a[i].vao >> a[i].ra >> a[i].tien;

	}

	sort(a.begin() + 1, a.begin() + n + 1);

	for (int i = 1; i <= n; i++) {
		x[i] = a[i].ra;
	}

	for (int i = 1; i <= n; i++) {
		int j = upper_bound(x.begin() + 1, x.begin() + i, a[i].vao) - x.begin() - 1;

		dp[i] = max(dp[i-1], a[i].tien + dp[j]);
	}

	cout << dp[n];
} 	

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
