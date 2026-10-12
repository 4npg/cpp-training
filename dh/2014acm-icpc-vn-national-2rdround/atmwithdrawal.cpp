# include<bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ri(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

const int _N = 1e6+5;
const int mod = 1e9 + 7;
const int inf = 1e9;

template <typename T> bool minimize(T &a, const T &b) { if (a > b) return a = b, true; return false; }
template <typename T> bool maximize(T &a, const T &b) { if (a < b) return a = b, true; return false; }
template <typename T> T opw(T a, T b) { T ans = 1; while (b) { if (b&1) ans = (ans * a) % mod; a = (a * a) % mod; b >>=1; } return ans; }
template <typename T> int size32 (const T &a) { return (int)a.size(); }

int sc (string num) {
    int s = 0;
    for (auto &c : num) s += c - '0';
    return s;
}

string sub; int cnt = 0;

void Try (int pos) {
    if (pos == 7) {
        // if (sub[6] == 1) return;
        cnt = cnt + (sc(sub) % 6 == 0);
        return;
    }

    for (char i = '1'; i <= '2'; i++) {
        sub = sub + i;
        Try(pos + 1);
        sub.pop_back();
    }

}

void solve() {

    sub = "";
    Try(0);
    cout << cnt;

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(nullptr);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}

