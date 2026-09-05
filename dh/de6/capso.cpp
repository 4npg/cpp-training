#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "capso"

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
// int d[N_];

// void sang() {
// 	d[0] = 0;
// 	d[1] = 1;
// 	for (int i = 1; i < N_; i++) {
// 		for (int j = i; j < N_; j += i) {
// 			d[j] += 1;
// 		}
// 	}
// }

long long calc(long long n) {
    long long ans = 0;

    for (long long l = 1; l <= n; ) {
        long long q = n / l;
        long long r = n / q;

        ans += (r - l + 1) * q;

        // cout << l << ' ' << r << ' ' << q << ' ' << ans << '\n';

        l = r + 1;
    }

    return ans;
}

void solve() {

	// sang();
	cin >> n;

	// for (int i = 1; i < 100; i++) {
	// 	cout << i << ':' << d[i] << '\n';
	// }
	
	cout << calc(n);

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
