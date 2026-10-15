#include <bits/stdc++.h>
using namespace std;

#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define file "plan"

const int N_ = 1005;

template <typename T> bool maximize (T &a, const T &b) {
    if (a < b) return a = b, true;
    return false;
}

int n, m, q, h, w;
long long a[N_][N_];

void solve() {

    cin >> n >> m >> q;
    for (int k = 0; k < q; k++) {
        int r1, c1, r2, c2;
        long long v;
        cin >> r1 >> c1 >> r2 >> c2 >> v;
        for (int i = r1; i <= r2; i++) {
            for (int j = c1; j <= c2; j++) {
                a[i][j] += v;
            }
        }
    }

    cin >> h >> w;

    int R = w;
    int C = h;


    long long ans = -4e18;
    for (int i = 1; i <= n - R + 1; i++) {
        for (int j = 1; j <= m - C + 1; j++) {
            long long cur = 0;
            for (int x = i; x < i + R; x++) {
                for (int y = j; y < j + C; y++) {
                    cur += a[x][y];
                }
            }
            // if (cur > ans) ans = cur;
            maximize(ans, cur);
        }
    }

    cout << ans;

}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";

}


 const int mod = 1e9 + 7;
    const int N_ = 1005;

    int n, k;
    int dp[N_][N_];

    // Legendre's formula to find exponent of prime p in n!
    int get_exponent(int n, int p) {
        int cnt = 0;
        while (n >= p) {
            cnt += n / p;
            n /= p;
        }
        return cnt;
    }

    // Build 2D DP table in O(K * N) using only additions
    void build_dp(int max_k, int max_alpha) {
        for (int j = 0; j <= max_alpha; j++) {
            dp[1][j] = 1;
        }
        for (int i = 1; i <= max_k; i++) {
            dp[i][0] = 1;
        }

        for (int i = 2; i <= max_k; i++) {
            for (int j = 1; j <= max_alpha; j++) {
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            }
        }
    }

    void solve() {
        if (!(cin >> n >> k)) return;

        if (k == 0) {
            cout << (n <= 1 ? 1 : 0) << '\n';
            return;
        }
        if (n <= 1) {
            cout << 1 << '\n';
            return;
        }

        // 1. Sieve primes up to n
        vector<bool> is_prime(n + 1, true);
        vector<int> primes;
        for (int i = 2; i <= n; i++) {
            if (is_prime[i]) {
                primes.push_back(i);
                for (int j = 2 * i; j <= n; j += i) {
                    is_prime[j] = false;
                }
            }
        }

        // 2. Build DP table up to k and max possible exponent (< n)
        build_dp(k, n);

        // 3. Multiply DP results for each prime factor
        long long ans = 1;
        for (int p : primes) {
            int alpha = get_exponent(n, p);
            ans = (ans * dp[k][alpha]) % mod;
        }

        cout << ans << '\n';
    }

    int32_t main(void) {
        ios_base::sync_with_stdio(0); cin.tie(0);

        // freopen(file".inp", "r", stdin);
        // freopen(file".out", "w", stdout);

        solve();

        cerr << "\ntime elapsed: " << TIME << "s.\n";
        return 0;
    }