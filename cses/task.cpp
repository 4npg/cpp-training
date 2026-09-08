#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int N_ = 1e3+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(T a, T &b) { if (a > b) return a = b, true; return false; }
template <typename T> bool maximize(T a, T &b) { if (a < b) return a = b, true; return false; }
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

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ri(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

int n, m;
int dx[] = {-1,0, 0, 1};
int dy[] = {0, -1, 1,0};

int d[N_][N_];
char a[N_][N_];

bool valid (int x, int y) {
    return ( (x >= 1 && x <= n) && (y >= 1 && y <= m) && a[x][y] == '0' && d[x][y] == -1);
}

void bfs () {
    queue< pair<int, int> > q; q.push({1, 1}); d[1][1] = 0;

    while (!q.empty()) {
        auto u = q.front(); q.pop();
        int x = u.first; int y = u.second;

        for (int k = 0; k <= 3; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];

            if (valid(nx, ny)) {
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
           }
        }
    }

}

void solve() {

    cin >> n >> m;
    
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }    
    memset(d, -1, sizeof d);

    bfs();

    if (a[1][1] == '1') {
        cout << -1;
        return;
    }

    cout << d[n][m];
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}

