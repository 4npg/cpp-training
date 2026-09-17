#include<bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "CAU2"

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(T a, T &b) { if (a > b) return a = b, 1; return 0; }
template <typename T> bool maximize(T a, T &b) { if (a < b) return a = b, 1; return 0; }
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

mt19937_64 rd (chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int ri (int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl (long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

long long calc(long long num) {
    long long res = 0, p = 1;
    while (num > 0) {
        long long d = num % 10;
        if (d != 0) {
            res += d * p;
            p *= 10;
        }
        num /= 10;
    }
    return res;
}

string add(const string &a, const string &b) {

	string ret = "";

	int i = size32(a) - 1; int j = size32(b) - 1;
	int du = 0;

	while (i >= 0 || j >= 0 || du) {
		int sum = du;
		if (i >= 0) sum += a[i--] - '0';
		if (j >= 0) sum += b[j--] - '0';
		ret += (char)('0' + sum % 10);
		du = sum / 10;
	}

	reverse(ret.begin(), ret.end());

	return ret;

}

string rm0 (const string &s) {

	string ret = "";
	for (char c : s) {
		if (c != '0') ret += c;
	}

	return ret.empty() ? "0" : ret;

}

void solve() {

    int t; cin >> t;
    // while (t--) {
    //     long long a, b;
    //     cin >> a >> b;
    //     long long c = a + b;
    //     cout << (calc(a) + calc(b) == calc(c) ? "YES" : "NO") << '\n';
    // }
    while (t--) {
    	string a, b; cin >> a >> b;
    	string c = add(a, b);
    	string vt = add(rm0(a), rm0(b));
    	string vp = rm0(c);

    	cout << (vt == vp ? "YES" : "NO") << '\n'; 
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}


