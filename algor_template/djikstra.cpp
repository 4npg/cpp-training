#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<ll, int>;

const ll INF = 1e18;
const int MAXN = 200005;

vector<pii> adj[MAXN];
ll dist[MAXN];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    while (m--) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        adj[u].push_back({w, v});
        adj[v].push_back({w, u});
    }

    fill(dist, dist + n + 1, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [du, u] = pq.top(); pq.pop();
        if (du != dist[u]) continue;

        for (auto [w, v] : adj[u]) {
            if (dist[v] > du + w) {
                dist[v] = du + w;
                pq.push({dist[v], v});
            }
        }
    }

    return 0;
}
