#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;

ll seg[4 * MAXN];
ll a[MAXN];
int n;

void build(int id, int l, int r) {
    if (l == r) {
        seg[id] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);
    seg[id] = seg[id*2] + seg[id*2+1];
}

void update(int id, int l, int r, int pos, ll val) {
    if (l == r) {
        seg[id] = val;
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(id*2, l, mid, pos, val);
    else update(id*2+1, mid+1, r, pos, val);
    seg[id] = seg[id*2] + seg[id*2+1];
}

ll query(int id, int l, int r, int u, int v) {
    if (v < l || r < u) return 0;
    if (u <= l && r <= v) return seg[id];
    int mid = (l + r) / 2;
    return query(id*2, l, mid, u, v) + query(id*2+1, mid+1, r, u, v);
}
