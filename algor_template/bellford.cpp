#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Edge { int u, v; ll w; };

const ll INF = 1e18;
vector<Edge> edges;
ll dist[200005];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    edges.resize(m);

    for (auto &e : edges) cin >> e.u >> e.v >> e.w;

    fill(dist, dist + n + 1, INF);
    dist[1] = 0;

    for (int i = 1; i < n; i++) {
        bool changed = false;
        for (auto &e : edges)
            if (dist[e.u] != INF && dist[e.v] > dist[e.u] + e.w) {
                dist[e.v] = dist[e.u] + e.w;
                changed = true;
            }
        if (!changed) break;
    }

    return 0;
}
