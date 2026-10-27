# include <bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file "monks"

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

int n;
vector < int > d;

struct State {
	vector < int > peg[3];

	bool operator < (const State &other) const {
		for (int i = 0; i < 3; i++) {
			if (peg[i] != other.peg[i]) return peg[i] < other.peg[i];
		}
		return false;
	}
	void init (int num_disks) {
		for (int i = 0; i < 3; i++) peg[i].clear();
		for (int i = 0; i < num_disks; i++) {
			peg[0].emplace_back(i);
		}
	}

	bool is_target () const {
		if (size32(peg[2]) != n) return false;
		for (int i = 0; i < n; i++) {
			if (peg[2][i] != i) return false;
		}
		return true;
	}

	bool can_move (int u, int v) const {
		if (u == v || peg[u].empty()) return false;
		if (peg[v].empty()) return true;

		int top_u = peg[u].back();
		int top_v = peg[v].back();
		return d[top_u] <= d[top_v];
	}

	void jump (int u, int v) {
		int disk = peg[u].back();
		peg[u].pop_back();
		peg[v].emplace_back(disk);
	}

	void undo (int u, int v) {
		int disk = peg[v].back();
		peg[v].pop_back();
		peg[u].emplace_back(disk);
	}

	State next_state (int u, int v) const {
		State ret = *this;
		int disk = ret.peg[u].back();
		ret.peg[u].pop_back();
		ret.peg[v].emplace_back(disk);
		return ret;
	}

} cur_state;

vector < pair <int, int> > path;

bool dfs (int depth, int mx_depth, int last_u, int last_v) {
	if (cur_state.is_target()) return true;
	if (depth == mx_depth) return false;

	for (int u = 0; u < 3; u++) {
		for (int v = 0; v < 3; v++) {
			if (u == last_v && v == last_u) continue;
			if (!cur_state.can_move(u, v)) continue;

			cur_state.jump(u, v);
			path.emplace_back(u + 1, v + 1);
			if (dfs(depth + 1, mx_depth, u, v)) return true;
			path.pop_back();
			cur_state.undo(u, v);
		}
	}
	return false;
}

void soldfs () {

	cin >> n; d.resize(n);
	for (int i = 0; i < n; i++) cin >> d[i];

	cur_state.init(n);

	for (int limit = 0; ; limit++) {
		if (dfs(0, limit, -1, -1)) {
			cout << limit << '\n';
			for (const auto &step : path) {
				cout << step.first << ' ' << step.second << '\n';
			}
			break;
		}
	}
}

void solbfs () { 

	cin >> n; d.resize(n);

	for (int i = 0; i < n; i++) cin >> d[i];
	State start;

	for (int i = 0; i < n; i++) start.peg[0].emplace_back(i);

	queue < State > q;
	map < State, pair < State, pair < int, int > > > par;
	map < State, bool > vis;

	q.push(start);
	vis[start] = true;

	State target_state; bool f = false;

	while (!q.empty()) {
		State cur = q.front(); q.pop();

		if (cur.is_target()) {
			target_state = cur;
			f = true;
			break;
		}

		for (int u = 0; u < 3; u++) {
			for (int v = 0; v < 3; v++) {
				if (!cur.can_move(u, v)) continue;

				State nxt = cur.next_state(u, v);
				if (!vis[nxt]) {
					vis[nxt] = true;
					par[nxt] = {cur, {u + 1, v + 1}};
					q.push(nxt);
				}
			}
		}
	}

	if (f) {
		vector < pair < int, int > > path;
		State curr = target_state;
		while (!(curr.peg[0] == start.peg[0] && curr.peg[1] == start.peg[1] && curr.peg[2] == start.peg[2])) {
			auto p = par[curr];
			path.emplace_back(p.second); curr = p.first;
		}
		reverse(path.begin(), path.end());

		cout << path.size() << '\n';

		for (const auto &step : path) {
			cout << step.first << ' ' << step.second << '\n';
		}
	}

}
	
int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solbfs();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


