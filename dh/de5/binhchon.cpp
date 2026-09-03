#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file "binhchon"

template<typename T> bool minimize (T &a, T b) { if (a > b) return a = b, 1; return 0; }
template<typename T> bool maximize (T &a, T b) { if (a < b) return a = b, 1; return 0; }

const int N_ = 1e5 + 5;
const int mod = (int)1e9 + 7;
const int base = 256;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int rd (int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

int n, m;
map<int, int> mp;
int ret = 0;

void solve() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		mp[x]++;
	}

	for (int i = 1; i <= m; i++) {
		maximize(ret, mp[i]);
	}

	cout << ret;
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	solve();

	cerr << "\ntime elapsed: " << TIME << "s.\n";
}
