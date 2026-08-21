#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "tchat"

const int N_ = 1e4+5;
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

int n, m;
char a[N_][300];
int cnt1, cnt2;

void solve() {
	
	cin >> m >> n;

	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			a[i][j] = s[j];
			if (a[i][j] == '1') {
				cnt1++;
            }
		}
	}

	for (int i = 0; i < m; i++) {
		int cur = 0;
		for (int j = 0; j < n; j++) {
			if (a[i][j] == '1') {
				cur++;
				cnt2 = max(cnt2, cur);
			} else cur = 0;
		}
	}

	for (int j = 0; j < n; j++) {
		int cur = 0;
		for (int i = 0; i < m; i++) {
			if (a[i][j] == '1') {
				cur++;
				cnt2 = max(cnt2, cur);
			} else cur = 0;
		}
	}

	cout << cnt1 << ' ' << cnt2;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
