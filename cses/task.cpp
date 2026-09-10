# include<bits/stdc++.h>
using namespace std;

# define TIME (1.0*clock()/CLOCKS_PER_SEC)
# define file ""

const int N_ = 1e5+5;
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

int N, M, L, Q;

// # define data pair<long long, int>

struct graph {

    struct data {
        int u; long long w;

        bool operator < (const data& other) {
            return w < other.w;
        }
    };

    int n; vector<vector<pair<int, long long>>> adj;

    long long d[N_];

    graph(int _n) : n(_n), adj(_n + 1) {}

    inline void add_edges(int u, int v, long long w) {
        adj[u].emplace_back(v, w);
    }

    void dijkstra(int s) {
        priority_queue<data, vector<data>, greater<data>> pq;
        memset(d, 0x3f, sizeof d);
        // pq.push({d[s] = 0, s}); 
        pq.emplace(d[s] = 0, s);

        while (!pq.empty()) {
            auto f = pq.top(); pq.pop();
            long long du = f.u; int u = f.w;

            for (auto &p : adj[u]) {
                int v = p.first; long long w = p.second;
                if (d[v] > d[u] + w) {
                    pq.emplace(d[v] = d[u] + w, v);
                }
            }
        }
    }

} g(N_);  

void solve() {

    cin >> N >> M >> L >> Q;

    for (int i = 0; i < M; i++) {
        int a, b; long long c;
        cin >> a >> b >> c;

        g.add_edges(a, b, c);
    }

    for (int i = 0; i < L; i++) {
        int u, v; long long w;
        cin >> u >> v >> w;

        g.add_edges(u, v, w);
    }

    while (Q--) {

    }
}

// void solve_incre() {

//     cin >> n;
//     vector<int> a(n + 1);

//     for (int i = 1; i <= n; i++) cin >> a[i];

//     // n = ri(1, 50005);

//     // cerr << n << '\n';

//     // for (int i = 1; i <= n; i++) {
//     //  a[i] = ri(1, n);
//     //  cerr << a[i] << ' ';
//     // }

//     for (int mx = 1; ; mx++) {
//         int l = mx * (mx + 1) / 2;
//         if (l > n) break;

//         memset(cnt, 0, (mx + 1) * sizeof(int));
//         int numcr = 0;
//         int valid = 0;

//         for (int i = 1; i <= l; i++) {
//             int x = a[i];
//             if (x <= mx) {
//                 if (cnt[x] == x) numcr--;
//                 cnt[x]++;
//                 if (cnt[x] == x) numcr++;
//             }
//         }

//         if (numcr == mx) valid++;

//         for (int i = l + 1; i <= n; i++) {
//             int hi = a[i - l];
//             int lo = a[i];

//             if (hi != lo) {
//                 if (hi <= mx) {
//                     if (cnt[hi] == hi) numcr--;
//                     cnt[hi]--;
//                     if (cnt[hi] == hi) numcr++;
//                 }

//                 if (lo <= mx) {
//                     if (cnt[lo] == lo) numcr--;
//                     cnt[lo]++;
//                     if (cnt[lo] == lo) numcr++;
//                 }
//             } 

//             if (numcr == mx) valid ++;
//         }

//         if (valid > 0) {
//             long long sum = 1LL * mx * (mx + 1) * (2 * mx + 1) / 6;

//             ret += 1LL * valid * sum;
//         }
//     }
    
//     cout << ret;
// }
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}

