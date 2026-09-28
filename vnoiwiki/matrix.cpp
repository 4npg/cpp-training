# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

const int N_ = 1e5+5;
const int mod = 1e9 + 7;
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

# define MAX_SIZE 20

struct mat {
    int n, m;
    long long d[MAX_SIZE][MAX_SIZE];
    mat(int _n = 0, int _m = 0) {
        n = _n; m = _m;
        memset(d, 0, sizeof d);
    }

    mat operator * (const mat &a) const {
        int x = n, y = m, z = a.m;

        mat res(x, z);
        for (int i = 0; i < x; i++)
            for (int j = 0; j < y; j++) {
                if (!d[i][j]) continue;
                for (int k = 0; k < z; k++) 
                    res.d[i][k] = (res.d[i][k] + d[i][j] * a.d[j][k]) % mod;
            }
        return res;
    }

    mat operator ^ (long long k) const  {
        mat res(m, m);
        for (int i = 0; i < m; i++) res.d[i][i] = 1;
        mat mul = *this;
        while (k > 0) {
            if (k & 1) res = res * mul;
            mul = mul * mul;
            k >>= 1;
        }
        return res;
    }

    long long *operator[] (int i) { return d[i]; }
    const long long * operator[] (int i) const { return d[i]; }

};

long long n;

void solve() {

    cin >> n;

    mat A(2, 2);
    A.d[0][0] = 0;
    A.d[0][1] = 1;
    A.d[1][0] = 1;
    A.d[1][1] = 1;
    mat F(2, 1);
    F.d[0][0] = 0;
    F.d[1][0] = 1;

    mat res = (A^n) * F;
    cout << res[0][0];

}


int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


