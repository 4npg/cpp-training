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

int n, m;
char a[N_][N_];
bool vis[N_][N_];

bool valid (int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != '#';
}
// int compo;
vector<int> cnt;

// void dfs (int ux, int uy) {
//     vis[ux][uy] = 1;
//     if (a[ux][uy] == 'x') cnt[compo]++;

//     for (int k = 0; k < 4; k++) {
//         int nx = ux + dx[k];
//         int ny = uy + dy[k];

//         if (!vis[nx][ny] && valid(nx, ny)) {
//             dfs(nx, ny);
//         }
//     }
// }

int bfs(int xi, int xj) {
    queue< pair<int, int> > q; q.push({xi, xj} );
    vis[xi][xj] = 1;

    int cnt = (a[xi][xj] == 'x');

    while (!q.empty()) {
        auto u = q.front(); int x = u.first; int y = u.second; q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (valid(nx, ny) && !vis[nx][ny]) {
                vis[nx][ny] = 1; cnt += (a[nx][ny] == 'x');
                q.push({nx, ny});
            }
        }
    }

    return cnt;

}

void solve() {

    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if ( valid(i, j) && !vis[i][j] ) {
                int temp = bfs(i, j);
                if (temp > 0) cnt.emplace_back(temp);
            }
        }
    }

    sort(cnt.begin(), cnt.end());
    for (auto &k : cnt) cout << k << ' ';

    // for (int i = 0; i <= compo; i++) {
    //     if (cnt[i] != 0) cout << cnt[i] << ' ';
    // }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
