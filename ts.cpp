 # include <bits/stdc++.h>
    using namespace std;

    # define TIME (1.0*clock()/CLOCKS_PER_SEC)
    # define file ""

    const int N_ = 1e3+5;
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

    int m, n;
    char a[N_][N_];

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};

    int d[N_][N_];
    bool vis[N_][N_];
    int jump_E[N_][N_];
    int jump_W[N_][N_];
    int jump_S[N_][N_];
    int jump_N[N_][N_];

    bool valid (int x, int y) {
        return (x >= 1 && x <= m && y >= 1 && y <= n);
    }

    bool is_land(int x, int y) {
        return a[x][y] != '1';
    }

    void precompute() {
        for (int i = 1; i <= m; i++) {
            int last = 0;
            for (int j = n; j >= 1; j--) {
                if (is_land(i, j)) last = j;
                else jump_E[i][j] = last;
            }
        }
        for (int i = 1; i <= m; i++) {
            int last = 0;
            for (int j = 1; j <= n; j++) {
                if (is_land(i, j)) last = j;
                else jump_W[i][j] = last;
            }
        }
        for (int j = 1; j <= n; j++) {
            int last = 0;
            for (int i = m; i >= 1; i--) {
                if (is_land(i, j)) last = i;
                else jump_S[i][j] = last;
            }
        }
        for (int j = 1; j <= n; j++) {
            int last = 0;
            for (int i = 1; i <= m; i++) {
                if (is_land(i, j)) last = i;
                else jump_N[i][j] = last;
            }
        }
    }

    int bfs (pair<int, int> st, pair<int, int> ed) {
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++) {
                d[i][j] = inf;
                vis[i][j] = false;
            }

        deque< pair <int, int> > dq;
        d[st.first][st.second] = 0;
        dq.push_back(st);

        while (!dq.empty()) {
            int x = dq.front().first;
            int y = dq.front().second;
            dq.pop_front();

            if (vis[x][y]) continue;
            vis[x][y] = true;

            if (x == ed.first && y == ed.second) {
                return d[x][y];
            }

            for (int k = 0; k < 4; k++) {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (valid(nx, ny) && is_land(nx, ny)) {
                    if (d[nx][ny] > d[x][y]) {
                        d[nx][ny] = d[x][y];
                        dq.push_front({nx, ny});
                    }
                }
            }

            if (y + 1 <= n && !is_land(x, y + 1) && jump_E[x][y + 1] != 0) {
                int ny = jump_E[x][y + 1];
                if (d[x][ny] > d[x][y] + 1) {
                    d[x][ny] = d[x][y] + 1;
                    dq.push_back({x, ny});
                }
            }

            if (y - 1 >= 1 && !is_land(x, y - 1) && jump_W[x][y - 1] != 0) {
                int ny = jump_W[x][y - 1];
                if (d[x][ny] > d[x][y] + 1) {
                    d[x][ny] = d[x][y] + 1;
                    dq.push_back({x, ny});
                }
            }

            if (x + 1 <= m && !is_land(x + 1, y) && jump_S[x + 1][y] != 0) {
                int nx = jump_S[x + 1][y];
                if (d[nx][y] > d[x][y] + 1) {
                    d[nx][y] = d[x][y] + 1;
                    dq.push_back({nx, y});
                }
            }

            if (x - 1 >= 1 && !is_land(x - 1, y) && jump_N[x - 1][y] != 0) {
                int nx = jump_N[x - 1][y];
                if (d[nx][y] > d[x][y] + 1) {
                    d[nx][y] = d[x][y] + 1;
                    dq.push_back({nx, y});
                }
            }
        }
        return -1;
    }

    void solve() {

        if (!(cin >> m >> n)) return;
        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                cin >> a[i][j];

        pair<int, int> st;
        pair<int ,int> ed;

        for (int i = 1; i <= m; i++)
            for (int j = 1; j <= n; j++)
                if (a[i][j] == '@') {
                    st = {i, j};
                } else if (a[i][j] == '#') ed = {i, j};

        precompute();

        int ret = bfs(st, ed);

        cout << ret;

    }

    int32_t main (void) {

        ios_base::sync_with_stdio(0); cin.tie(0);

        solve();

        cerr << "\ntime elapsed: " << TIME << "s.\n";

    }