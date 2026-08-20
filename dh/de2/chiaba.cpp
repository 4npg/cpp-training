#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "chiaba"

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template<class T> bool minimize(T a, T &b) { if (a > b) return a = b, true; return false; }
template<class T> bool maximize(T a, T &b) { if (a < b) return a = b, true; return false; }
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
int a[N_];
long long pre;

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		pre += a[i];
	}

	if (pre % 3 != 0) {
		cout << 0;
		return;
	}

	long long tmp = pre / 3;

	long long cnt1 = 0, cnt2 = 0;
	pre = 0;
	// cout << tmp;

	for (int i = 0; i < n - 1; i++) {
		pre += a[i];

		if (pre == 2 * tmp) {
			cnt2 += cnt1;
		}

		if (pre == tmp) {
			cnt1 ++;
		}
	}

	cout << cnt2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

     freopen(file".inp", "r", stdin);
     freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}
