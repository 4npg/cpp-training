#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "hoahong"

const int N_ = 1e5+5;
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

long long x, y;

bool tachso (long long n) {
	while (n) {
		if (n % 10 != 7 && n % 10 != 9) return false;
		n /= 10;
	}
	return true;
}

long long ret;

void Try(long long n) {
	if (n > y) return;

	if (n >= x) {
		// cout << n << ' ';
		ret++;
	}

	if (n > (y - 7) / 10) return;

	Try(n * 10 + 7);
	Try(n * 10 + 9);

}

void solve() {

	cin >> x >> y;

	// for (long long i = x; i <= y; i++) {
	// 		if (tachso(i)) {
	// 			ret ++;
	// 		}
	// }

	Try(0);

	// cout << '\n';

	cout << ret;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

     freopen(file".inp", "r", stdin);
     freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}
