# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(T &a, T b) { if (a > b) return a = b, 1; return 0; }
template <typename T> bool maximize(T &a, T b) { if (a < b) return a = b, 1; return 0; }
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

mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int ri (int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

string s;
map<char, int> mp;
int cntV, cntD; int ret = 0;

void sub1() {

	cin >> s;

	for (int i = 0; i < size32(s); i++) {
		string tmp = ""; int len = 0; map<char, int> mp1;
		for (int j = i; j < size32(s); j++) {
			tmp += s[j];
			mp1[s[j]]++;
			if(mp1['V'] == mp1['D'] * 2) maximize(len, j - i + 1);
		}
		maximize(ret, len);
	}

	cout << ret;
}

void solve () {

	cin >> s;
	int n = size32(s);
	unordered_map<int, int> f_idx;
	f_idx[0] = 0;

	int pref = 0;
	for (int i = 1; i <= n; i++) {
		pref += ((s[i - 1] == 'V') ? 1 : -2);

		if (f_idx.count(pref)) {
			maximize(ret, i - f_idx[pref]);
		} else f_idx[pref] = i;
		
	}

	cout << ret;

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


