#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;

ll seg[4 * MAXN];
ll lazy[4 * MAXN];
ll a[MAXN];
int n;

// Đẩy lazy từ node hiện tại xuống 2 node con
void push(int id, int l, int r) {
    if (lazy[id] == 0) return;

    seg[id] += (r - l + 1) * lazy[id];

    if (l != r) { 
        lazy[id * 2] += lazy[id];
        lazy[id * 2 + 1] += lazy[id];
    }

    lazy[id] = 0;
}

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

// Update cộng thêm val vào đoạn [u, v]
void update(int id, int l, int r, int u, int v, ll val) {
    push(id, l, r);

    if (r < u || v < l) return; // không giao
    if (u <= l && r <= v) {
        lazy[id] += val;
        push(id, l, r);
        return;
    }

    int mid = (l + r) >> 1;
    update(id * 2, l, mid, u, v, val);
    update(id * 2 + 1, mid + 1, r, u, v, val);
    seg[id] = seg[id * 2] + seg[id * 2 + 1];
}

// Query tổng đoạn [u, v]
ll query(int id, int l, int r, int u, int v) {
    push(id, l, r);

    if (r < u || v < l) return 0; 
    if (u <= l && r <= v) return seg[id];

    int mid = (l + r) >> 1;
    return query(id * 2, l, mid, u, v)
         + query(id * 2 + 1, mid + 1, r, u, v);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    build(1, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int type, l, r;
        cin >> type >> l >> r;

        if (type == 1) {
            ll val;
            cin >> val;
            update(1, 1, n, l, r, val);
        } else {
            cout << query(1, 1, n, l, r) << "\n";
        }
    }
    return 0;
}
