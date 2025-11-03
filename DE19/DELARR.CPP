// author : anphung >> npkly
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()

const int MAXN = 300000 + 5;

int n, m;
int bit[MAXN];

void update(int i, int v) {
    for (; i <= n; i += i & -i)
        bit[i] += v;
}

int get(int i) {
    int s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

int find_kth(int k) {
    int pos = 0;
    for (int i = 1 << 22; i; i >>= 1) {
        if (pos + i <= n && bit[pos + i] < k) {
            k -= bit[pos + i];
            pos += i;
        }
    }
    return pos + 1;
}

int32_t main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file("DELARR");
    cin >> n >> m;
    vector<int> q(m);
    for (int i = 0; i < m; ++i) cin >> q[i];

    for (int i = 1; i <= n; ++i)
        update(i, 1);

    for (int x : q) {
        int total_alive = get(n);
        if (x > total_alive) { 
            cout << 0 << '\n';
            continue;
        }
        int idx = find_kth(x);
        cout << idx << '\n';
        update(idx, -1);
    }

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}
