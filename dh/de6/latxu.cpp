#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "latxu"

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
int cnt;

struct node {
	int val;
	int len;

	node(int val, int len) : val(val), len(len) {}
};

void print() {
	for (int i = 1; i <= n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}

void trau() {
	cin >> n;
	// for (int i = 1; i <= n; i++) {
	// 	cin >> a[i];
	// 	if (!(i & 1) && a[i] != a[i-1]) {
	// 		int j = i - 1;
	// 		while (a[j] != a[i]) {
	// 			if (j == 0) break;
	// 			a[j] ^= 1;
	// 			// if (a[j] == 1) a[j] = 0;
	// 			// else a[j] = 1;
	// 			j--;
	// 		}
	// 	}
	// }

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!(i & 1) && a[i] != a[i - 1]) {
			int j = i - 1;
			while (a[j] != a[i]) {
				if (j == 0) break;
				a[j] ^= 1;
				j--;
			}
			// print();
		}
	}
	for (int i = 1; i <= n; i++) {
		// cout << a[i] << ' ';
		cnt += (a[i] == 0) ? 1 : 0;
	}

	// cout << '\n';

	cout << cnt;
}

void solve() {

	cin >> n; 
	// n = ri(16, 16);
	// cerr << n << '\n';
	vector<node> st;

	for (int i = 1; i <= n; i++) {
		int x; cin >> x;
		// int x = ri(0, 1);
		// cerr << x << ' ';
		if (i & 1) {
			if (!st.empty() && st.back().val == x) st.back().len++;
			else st.emplace_back(x, 1);

			continue;
		} 

		if (st.back().val == x) {
			st.back().len++;
		} else {
			st.back().val ^= 1;
			// st.back().len++;

			if (st.size() >= 2 && st[st.size() - 2].val == st.back().val) {
				st[st.size() - 2].len += st.back().len;
				st.pop_back();
			}

			if (!st.empty() && st.back().val == x) st.back().len++;
			else st.emplace_back(x, 1);
		}
	}

	// for (auto &nod : st) {

	// 	int val = nod.val; int len = nod.len;
	// 	cout << nod.val << ' ' << nod.len << '\n';

	// }

	// return ;

	for (auto &nod:st) {
		int val = nod.val;
		int len = nod.len;
		if (val == 0) cnt += len;
	}

	cout << cnt;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();
    // trau();
    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
