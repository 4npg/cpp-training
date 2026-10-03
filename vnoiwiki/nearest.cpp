# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

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

int n, m, b, r;
vector <int> ba, ra;

struct edge {
    int n;
    vector < vector <int> > adj;
    vector < int > d;

    edge(int n_) : n(n_), adj(n_), d(n_) {}

    inline void add_edges(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

    void bfs (vector <int> &source) {
        fill(d.begin(), d.end(), -1);
        queue <int> q;

        for (auto &s : source) {
            d[s] = 0; q.push(s);
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();

            for (auto &v : adj[u]) {
                if (d[v] == -1) {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
    }


};

void solve() {

    cin >> n >> m >> b >> r;
    ba.resize(b);
    ra.resize(r);

    edge g(n + 1);

    for (int i = 0; i < b; i++) 
        cin >> ba[i];

    for (int i = 0; i < r; i++) 
        cin >> ra[i];

    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g.add_edges(u, v);
    }

    g.bfs(ba);

    for (int i = 0; i < r; i++) {
        cout << g.d[ra[i]] << ' ';
    }
    
}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


