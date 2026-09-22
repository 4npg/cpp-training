# include<bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "fibo"

const int N_ = 1e5+5;
const int mod = 1e9 + 7;
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

int n;

# define MATRIX_SIZE 55

struct Matrix {
	int n, m;
	long long d[MATRIX_SIZE][MATRIX_SIZE];

	Matrix(int _n = 0, int _m = 0) {
		n = _n; m = _m; memset(d, 0, sizeof d);
	}

	Matrix operator + (const Matrix &a) const {
		Matrix res(n, m);
		for (int i = 0; i < n; i++) 
			for (int j = 0; j < m; j++) {
				res.d[i][j] = d[i][j] + a.d[i][j];
				if (res.d[i][j] >= mod) res.d[i][j] -= mod;
			}
		return res;
	}

	Matrix operator * (const Matrix &a) const {
		int x = n, y = m, z = a.m;
		Matrix res(x, z);
		for (int i = 0; i < x; i++) 
			for (int j = 0; j < y; j++)
					for (int k = 0; k < z; k++) {
						res.d[i][k] += 1LL * d[i][j] * a.d[j][k];
						if (res.d[i][k] >= 1LL * mod * mod) res.d[i][k] -= 1LL * mod * mod;
					}
		for (int i = 0; i < x; i++) for (int k = 0; k < z; k++) res.d[i][k] %= mod;

		return res;
	}

	Matrix operator ^ (long long k) const {
		Matrix res(n, n);
		for (int i = 0; i < n; i++) res.d[i][i] = 1;
		Matrix mul = *this;
		while (k > 0) {
			if (k & 1) res = res * mul;
			mul = mul * mul;
			k >>= 1;
		}
		return res;
	}

	long long *operator[] (int i) {
		return d[i];
	}

	const long long * operator[] (int i) const {
		return d[i];
	}
};

void mtrx() {
	Matrix v(1, 2);
	v.d[0][0] = 1;
	v.d[0][1] = 1;

	Matrix A(2, 2);
	A.d[0][0] = 1;
	A.d[0][1] = 1;
	A.d[1][0] = 1;
	A.d[1][1] = 0;

	long long nn; cin >> nn;
	Matrix res = v * (A ^ nn);

	cout << res.d[0][1];
}

void solve() {

	cin >> n;
	long long f0 = 1, f1 = 1;

	for (int i = 2; i <= n; i++) {
		long long f2 = (f0 + f1) % mod;
		f0 = f1;
		f1 = f2;
	}

	cout << f1;
}

int main (void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();
    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}


