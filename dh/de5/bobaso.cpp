#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file "bobaso"

template<typename T> bool minimize (T &a, T b) { if (a > b) return a = b, 1; return 0; }
template<typename T> bool maximize (T &a, T b) { if (a < b) return a = b, 1; return 0; }

const int N_ = 1e5 + 5;
const int mod = (int)1e9 + 7;
const int base = 256;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int rd (int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

bool d[N_];
vector<int> nto;

void sang() {
	d[0] = d[1] = 1;
	for (int i = 2; i * i < N_; i++) {
		if (!d[i]) for (int j = i * i; j < N_; j += i) {
			d[j] = 1;
		}
	}

	for (int i = 2; i < N_; i++) {
		if (!d[i]) nto.emplace_back(i);
	}
}

int k;

void solve() {

	sang(); cin >> k;

	// for (int i = 2; i < 100; i++) {
	// 	if (!d[i]) cout << i << ' ' ;
	// }

	// for (int x = 2; x <= k; x++) {
	// 	if (!d[x]) for (int y = x; y <= k - x; y++) {
	// 		if (!d[y]) for (int z = y; z <= k - x - y; z++) {
	// 			if (!d[z])
	// 				if (x + y + z == k) cout<< x << ' ' << y << ' ' << z << '\n';
	// 		}
	// 	}
	// }

	for (int x : nto) {
		if (x > k / 3) break;

		for (int y : nto) {
			if (y < x) continue;
			if (y > (k - x) / 2) break;

			int z = k - x - y;

			if(!d[z]) cout << x << ' ' << y << ' ' << z << '\n';
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(0); cin.tie(0);

	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	solve();

	cerr << "\ntime elapsed: " << TIME << "s.\n";
}
