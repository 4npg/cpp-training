#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = LLONG_MAX;

struct Edge {
    int v;
    int w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<Edge>> g(N + 1);

    for (int i = 0; i < M; i++) {
        int K, U, V, L;
        cin >> K >> U >> V >> L;
        g[U].push_back({V, L});
        if (K == 2) {
            g[V].push_back({U, L});
        }
    }

    vector<ll> dist(N + 1, INF);
    vector<ll> cnt(N + 1, 0);

    priority_queue<pair<ll,int>, vector<pair<ll,int>>, greater<>> pq;

    dist[1] = 0;
    cnt[1] = 1;
    pq.push({0, 1});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto &e : g[u]) {
            int v = e.v;
            ll w = e.w;

            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                cnt[v] = cnt[u];
                pq.push({dist[v], v});
            }
            else if (dist[v] == dist[u] + w) {
                cnt[v] += cnt[u];
            }
        }
    }

    cout << dist[N] << " " << cnt[N];
}
