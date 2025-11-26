#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n+1);
        sz.assign(n+1, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int u) {
        return (parent[u] == u ? u : parent[u] = find(parent[u]));
    }

    bool unite(int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;

        if (sz[u] < sz[v]) swap(u, v);
        parent[v] = u;
        sz[u] += sz[v];
        return true;
    }
};

int main() {
    DSU dsu(100000);

    dsu.unite(1, 2);
    dsu.unite(2, 3);

    return 0;
}
