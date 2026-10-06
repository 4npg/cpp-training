#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

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

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ri(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

const int N_ = 1e3+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

int dx[] = {-1,0, 0, 1};
int dy[] = {0, -1, 1,0};

template <typename T> bool minimize(T &a, const T &b) { if (a > b) return a = b, true; return false; }
template <typename T> bool maximize(T &a, const T &b) { if (a < b) return a = b, true; return false; }
template <typename T> T opw(T a, T b) { T ans = 1; while (b) { if (b&1) ans = (ans * a) % mod; a = (a * a) % mod; b >>=1; } return ans; }
template <typename T> int size32 (const T &a) { return (int)a.size(); }

int n;

void solve() {

    cin >> n;
    if (n % 4 == 1 || n% 4 == 2) {
        cout << "NO\n";
        return;
    }

    vector <int> a, b;

    if (n % 4 == 3) {
        a.emplace_back(1);
        a.emplace_back(2);
        b.emplace_back(3);

        for (int i = 4; i <= n; i += 4) {
            a.emplace_back(i);
            a.emplace_back(i + 3);

            b.emplace_back(i + 1);
            b.emplace_back(i + 2);
        }
    } else {
        for (int i = 1; i <= n; i += 4) {
            a.emplace_back(i);
            a.emplace_back(i + 3);

            b.emplace_back(i + 1);
            b.emplace_back(i + 2);
        }
    }

    cout << "YES\n";
    cout << size32(a) << '\n';
    for (int x : a) cout << x << ' ';
    cout << '\n';
    cout << size32(b) << '\n';
    for (int x : b) cout << x << ' ';

}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
