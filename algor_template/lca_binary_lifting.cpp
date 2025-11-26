#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
const int LOG = 20;

vector<int> adj[MAXN];
int up[LOG][MAXN];
int depth[MAXN];
int n;

void dfs(int u, int p) {
    up[0][u] = p;

    for (int v : adj[u]) {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dfs(v, u);
    }
}

int lca(int a, int b) {
    if (depth[a] < depth[b]) swap(a, b);

    int k = depth[a] - depth[b];
    for (int i = 0; i < LOG; i++)
        if (k >> i & 1)
            a = up[i][a];

    if (a == b) return a;

    for (int i = LOG-1; i >= 0; i--) {
        if (up[i][a] != up[i][b]) {
            a = up[i][a];
            b = up[i][b];
        }
    }

    return up[0][a];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    depth[1] = 0;
    dfs(1, 0);

    for (int i = 1; i < LOG; i++)
        for (int v = 1; v <= n; v++)
            up[i][v] = up[i-1][ up[i-1][v] ];

    // ví dụ: cout << lca(4, 7);
}
