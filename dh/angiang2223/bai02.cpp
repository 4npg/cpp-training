# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "bai02"

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

void solve() {

    cin >> s;
    s = ' ' + s;
    // for (int i = 1; i < size32(s); i++) cout << s[i] << ' ';
    // cout << '\n';
    
    int lo = 1, len = 0, pos = 1;

    for (int hi = 1; hi < size32(s); hi++) {

        while (mp[s[hi]] == 1) {
            mp[s[lo++]]--;
        }

        mp[s[hi]]++;

        if (maximize(len, hi - lo + 1)) pos = lo;
    }

    for (int i = pos; i < pos + len; i++) cout << s[i];

    // int lo = 0, hi = size32(s) - 1;

    // cout << lo << ' ' << s[lo] << '\n';
    // cout << hi << ' ' << s[hi] << '\n';

    // while (lo < hi) {

    // }

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}
