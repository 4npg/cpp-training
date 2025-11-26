#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;

ll bit[MAXN];
int n;

void update(int i, ll val) {
    for (; i <= n; i += i & -i)
        bit[i] += val;
}

ll query(int i) {
    ll s = 0;
    for (; i > 0; i -= i & -i)
        s += bit[i];
    return s;
}

ll range_query(int l, int r) {
    return query(r) - query(l - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        ll x; cin >> x;
        update(i, x);
    }
}
