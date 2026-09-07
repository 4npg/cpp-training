#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int N_ = 1e5+5;
const int mod = 1e9 + 2277;
const int inf = 1e9;
const int base = 256;

template<class T> bool minimize(T a, T &b) { if (a > b) return a = b, true; return false; }
template<class T> bool maximize(T a, T &b) { if (a < b) return a = b, true; return false; }
template<class T> T opw(T a, T b) { T ans = 1; while (b) { if (b&1) ans = (ans * a) % mod; a = (a * a) % mod; b >>=1; } return ans; }

mt19937_64 rd(chrono::steady_clock::now().time_since_epoch().count());
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int ri(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

long long rl(long long l, long long r) {
    return uniform_int_distribution<long long>(l, r)(rd);
}

int t;

void solve() {
    cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int &x : a) cin >> x;

        vector<int> pos;
        for (int i = 0; i < n; i++) {
            if (a[i] != 0) pos.push_back(i);
        }

        if (pos.empty()) {
            for (int i = 0; i < n; i++) cout << 0 << ' ';
            cout << '\n';
            continue;
        }

        int bestL = pos[0], bestR = pos[0];
        int maxDist = 1;

        for (int i = 0; i + 1 < (int)pos.size(); i++) {
            int l = pos[i];
            int r = pos[i + 1];

            bool hasFixedOne = false;
            for (int k = l + 1; k < r; k++) {
                if (a[k] == 1) {
                    hasFixedOne = true;
                    break;
                }
            }

            if (!hasFixedOne) {
                int dist = r - l + 1;
                if (dist > maxDist) {
                    maxDist = dist;
                    bestL = l;
                    bestR = r;
                }
            }
        }

        vector<int> ans = a;
        ans[bestL] = 1;
        ans[bestR] = 1;

        for (int i = bestL + 1; i < bestR; i++) {
            if (ans[i] == -1) ans[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            if (ans[i] == -1) ans[i] = 0;
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n"; 
}
