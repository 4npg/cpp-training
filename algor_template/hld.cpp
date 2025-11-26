#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAXN = 200005;

vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN];
int head[MAXN], pos[MAXN];
int sz[MAXN];
int cur_pos = 0;

int dfs(int u) {
    sz[u] = 1;
    int mx = 0;
    for (int v : adj[u]) {
        if (v == parent[u]) continue;
        parent[v] = u;
        depth[v] = depth[u] + 1;
        int s = dfs(v);
        sz[u] += s;
        if (s > mx) {
            mx = s;
            heavy[u] = v;
        }
    }
    return sz[u];
}

void decompose(int u, int h) {
    head[u] = h;
    pos[u] = ++cur_pos;

    if (heavy[u]) decompose(heavy[u], h);

    for (int v : adj[u])
        if (v != parent[u] && v != heavy[u])
            decompose(v, v);
}

int lca(int a, int b) {
    while (head[a] != head[b]) {
        if (depth[head[a]] > depth[head[b]])
            a = parent[head[a]];
        else b = parent[head[b]];
    }
    return depth[a] < depth[b] ? a : b;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(1);
    decompose(1, 1);

    // pos[u] là vị trí node u trong segment tree
}
