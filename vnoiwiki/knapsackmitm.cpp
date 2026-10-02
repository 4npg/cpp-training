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

# define DATA pair <int, int>

int n, s;
// int w[N_], v[N_];
// pair <int, int> node[N_];
vector < DATA > node;
vector < DATA > node_a, node_b;

int ret;

bool cmp (DATA node_a, DATA node_b){
    return node_a.first < node_b.first;
}

void Try (int pos, int weight, int profit) {

    if (weight > s) return;
    if (pos > n) {
        maximize(ret, profit); 
    } else {
        Try (pos + 1, weight, profit);
        Try (pos + 1, weight + node[pos].first, profit + node[pos].second);
    }

}

void mitm (int pos, int limit, int weight, int profit, vector < DATA > &a) {

    if (weight > s) return;
    if (pos > limit) {
        a.emplace_back(weight, profit);
    } else {
        mitm(pos + 1, limit, weight, profit, a);
        mitm(pos + 1, limit, weight + node[pos].first, profit + node[pos].second, a);
    }

} 

void solve() {

    cin >> n >> s; node.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> node[i].first >> node[i].second;
    }

    // Try(0, 0, 0);

    mitm(1, n / 2, 0, 0, node_a);
    mitm(n / 2 + 1, n, 0, 0, node_b);

    sort(node_b.begin(), node_b.end(), cmp);

    vector < DATA > filte_b;
    int max_val = -inf;

    for (const auto &it : node_b) {
        if (it.second > max_val) {
            filte_b.emplace_back(it);
            max_val = it.second;
        }
    }

    // for (const auto &it : node_a) {
    //     int x = s - it.first;
    //     if (x < 0) continue;

    //     auto idx = upper_bound(filte_b.begin(), filte_b.end(), make_pair(x, inf));
    //     if (idx != filte_b.begin()) {
    //         --idx;
    //         maximize(ret, it.second + idx->second);
    //     }
    // }

    for (const auto &it : node_a) {
        int x = s - it.first;
        if ( x < 0 ) continue;

        int p = upper_bound(filte_b.begin(), filte_b.end(), make_pair(x, inf)) - filte_b.begin() - 1;
        if (p >= 0) {
            maximize(ret, it.second + filte_b[p].second);
        }
    }

    cout << ret;

}

int32_t main (void) {

    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 

}


