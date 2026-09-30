# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "bai01"

const int N_ = 5e6+5;
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

int d[N_]; int id[N_];
vector <int> p;

void sang () {
    d[0] = d[1] = 1;

    for (int i = 2; i * i < N_; i++) 
        if (!d[i]) for (int j = i * i; j < N_; j += i) d[j] = 1;

    // for (int i = 2; i < N_; i++) 
    //     if (!d[i]) p.emplace_back(i);

    for (int i = 1; i < N_; i++) id[i] = 1;

    for (int i = 2; i < N_; i++) if (!d[i]) for (int j = i; j < N_; j += i) id[j] *= i;

}

set <int> tsnto (int a) {

    set <int> ret;

    for (auto &x : p) {
        if (a % x == 0) {
            while (a % x == 0) {
                a /= x;
                ret.insert(x);
            }
        }
    }

    if (a > 1) ret.insert(a);

    return ret;

}

int l, r;
int ret;


vector < pair<int, int> > ans;

void solve() {

    sang();

    cin >> l >> r;

    map < int, vector <int> > mp;

    for (int i = l; i <= r; i++) mp[id[i]].emplace_back(i);

    for (auto &q : mp) {
        int x = q.first; vector <int > y = q.second;

        for (int i = 0; i < size32(y); i++) {
            for (int j = i + 1; j < size32(y); j++) {
                ret++;
                ans.emplace_back(y[i], y[j]);
            }
        }
    }

    cout << ret << '\n';

    // for (int i = l; i <= r; i++) {
    //     for (int j = i + 1; j <= r; j++) {
    //         if (tsnto(i) == tsnto(j)) {
    //             ret++;
    //             ans.emplace_back(i, j);
    //         }
    //     }
    // }

    // cout << ret << '\n';

    for (auto &x : ans) {
        cout << x.first << ' ' << x.second << '\n';
    }

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
     freopen(file".inp", "r", stdin);
     freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}
