# include<bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template <typename T> bool minimize(T a, T &b) { if (a > b) return a = b, 1; return 0; }
template <typename T> bool maximize(T a, T &b) { if (a < b) return a = b, 1; return 0; }
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

mt19937_64 rd (chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng (chrono::steady_clock::now().time_since_epoch().count());

int ri (int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl (long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

struct graph {
	int n;
	vector < vector <int> > adj;
	vector <int> vis; stack<int> topo;
	vector<int> ans;

	graph(int n_) : n(n_), adj(n_ + 1), vis(n_ + 1), ans(n_ + 1) {}

	inline void add_edges(int u, int v) {
		adj[u].emplace_back(v);
	}

	void dfs(int u) {
		vis[u] = 1;
		for (auto v : adj[u]) {
			if (vis[v] == 1) {
				cout << "Graph contains a cycle";
				exit(0);
			}
			if (!vis[v]) dfs(v);
		}
		topo.push(u);
		vis[u] = 2;
	}

	void calc() {

		for (int i = 1; i <= n; i++) {
			if (!vis[i]) dfs(i);
		}

		int cnt = 0;
		while (!topo.empty()) {
			ans[topo.top()] = ++cnt;
			topo.pop();
		}

		for (int i = 1; i <= n; i++) {
			cout << ans[i] << ' ' ;
		}
	}	

};

int n, m;

void solve() {
	cin >> n >> m;

	graph g(n);

	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v;
		g.add_edges(u, v);
	}

	g.calc();
}

int main (void) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}


