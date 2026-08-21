#include<bits/stdc++.h>
#include <chrono>
#include <ctime>
#include <random>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int N_ = 1e5+5;
const int mod = (int)1e9 + 7;
const int base  = 256;

template<typename T> bool minimize(T &a, T b) { return a > b ? a = b, 1 : 0; }
template<typename T> bool maximize(T &a, T b) { return a < b ? a = b, 1 : 0; }
template<typename T> T opw (T &a, T b) { T ans = 1; while(b) { if (b & 1) ans = (ans * a) % mod; a = (a * a) % mod; b >>= 1; } return ans; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rd(int l, int r) {
	return uniform_int_distribution<int>(l, r)(rng);
}

int p, t, m;

long long cal(int p) {
        long long ret = 0;

        for (int i = 1; i <= p; i++) {
                // int h = st + i;
                long long tmp = (m == 1) ? 600 : 900;

                if (i > 10) tmp = tmp * 50 / 100;

                ret += tmp;
        }

        return ret;
}

void solve() {
	cin >> p >> t >> m;

	if ( t == 1 || t == 7 ) {cout << cal(p) - (cal(p) * 30 / 100) ; return; }

	cout << cal(p);
}

int main(void) {

	ios_base::sync_with_stdio(0); cin.tie(0);

	// freopen("tiendt.inp", "r", stdin);
	// freopen("tiendt.out", "w", stdout);

	solve();

	cerr << "\ntime elapsed: " << TIME << "s.\n";
}