#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "fibo"

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

int n;
string querry;
vector<string> s(N_);

void solve() {

    cin >> n >> querry;

    s[0] = "A";
    s[1] = "B";

    for (int i = 2; i <= n; i++)
        s[i] = s[i - 2] + s[i - 1];

    int m = querry.size();

    vector<int> pi(m);

    for (int i = 1; i < m; i++) {
        int j = pi[i - 1];

        while (j && querry[i] != querry[j])
            j = pi[j - 1];

        if (querry[i] == querry[j])
            ++j;

        pi[i] = j;
    }

    long long ans = 0;
    int j = 0;

    for (char c : s[n]) {
        while (j && c != querry[j])
            j = pi[j - 1];

        if (c == querry[j])
            ++j;

        if (j == m) {
            ++ans;
            ans %= mod;
            j = pi[j - 1];
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);

     freopen(file".inp", "r", stdin);
     freopen(file".out", "w", stdout);

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}
