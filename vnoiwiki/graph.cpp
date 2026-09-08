#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template<class T> bool minimize(T a, const T &b) { if (a > b) return a = b, true; return false; }
template<class T> bool maximize(T a, const T &b) { if (a < b) return a = b, true; return false; }
template<class T> T opw(T a, T b) { T ans = 1; while (b) { if (b&1) ans = (ans * a) % mod; a = (a * a) % mod; b >>=1; } return ans; }
template<typename T> int size32 (const T &a) { return (int)a.size(); }

template<typename T, int D> 
struct Vec : public vector<Vec<T, D - 1>> {
	static_assert(D >= 1, "Error");
	template <typename ... Args>
	Vec(int n = 0, Args... args)
		: vector<Vec<T, D - 1>>(n, Vec<T, D - 1>(args...)) {}
};

template<typename T> struct Vec<T, 1> : public vector<T> {
	Vec(int n = 0, const T &val = T()) : vector<T>(n, val) {}
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

struct graph {
    int n; Vec<int, 2> adj;
    graph (int _n) : n (_n), adj (_n + 1) {}

    void add_edges(int u, int v) {
        adj[u].emplace_back(v);
    }
};

bool vis[N_];

void dfs (int u, const graph &g) {
    vis[u] = 1;

    for (int v : g.adj[u]) {
        if (!vis[v]) {
            dfs(v, g);
        }
    }
}

int d[N_];
int minimum_path = inf;
int par[N_];

void bfs (int s, const graph &g) {
    par[s] = s;
    queue<int> q; q.push(s); vis[s] = 1;

    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g.adj[u]) {
            if (!vis[v]) {
                q.push(v);
                d[v] = d[u] + 1;
                vis[v] = 1;
                par[v] = u;
            }
        }
    }

}

int ret = 0;
Vec<int, 1> path;

void solve() {
    cin >> n >> m; 
    graph g(n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        g.add_edges(u, v);
        g.add_edges(v, u);
    }

    // for (int i = 1; i <= n; i++) {
    //     if (!vis[i]) {
    //         // dfs(i, g);
    //         bfs(i, g);
    //         ret++;
    //     }
    // }
    // cout << ret;

    bfs(1, g);

    int vertical = n;

    while (true) {
        path.emplace_back(vertical);
        if (vertical == 1) break;
        else vertical = par[vertical];
    }

    reverse(path.begin(), path.end());

    cout << d[n] << '\n';
    for (auto &k : path) cout << k << ' ';

    // for (int i = 2; i <= n; i++) {
    //     cout << (! (d[i] == 0) ? d[i] : -1 ) << ' ';
    // }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}

