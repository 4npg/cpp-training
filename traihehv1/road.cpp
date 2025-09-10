#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define ALL(v)   (v).begin(), (v).end()
#define fi   first
#define se   second

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }

const long long INF = (long long)1e18 + 7LL;

#define MAX   100100
int numNode, numEdge, destVinh, limitVinh;
vector<pair<int, int>> adjBike[MAX], revAdjBike[MAX], revAdjWalk[MAX];
long long distFromOne[MAX], distToN[MAX], distToK[MAX];

void loadGraph(void) {
    cin >> numNode >> numEdge >> destVinh >> limitVinh;
    REP(faker, numEdge) {
        int fr, to, bike, walk; cin >> fr >> to >> walk >> bike;
        adjBike[fr].push_back(make_pair(to, bike));
        revAdjBike[to].push_back(make_pair(fr, bike));
        revAdjWalk[to].push_back(make_pair(fr, walk));
    }
}

void dijkstra(int start, vector<pair<int, int>> adj[], long long dist[]) {
    FOR(i, 1, numNode) dist[i] = INF;

    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> q;

    #define PUSH(s) q.push(make_pair(dist[s], s))
    dist[start] = 0; PUSH(start);

    while (!q.empty()) {
        long long d = q.top().fi;
        int u = q.top().se;
        q.pop();
        if (d != dist[u]) continue;

        for (const pair<int, int> &e : adj[u]) {
            int v = e.fi, c = e.se;
            if (minimize(dist[v], dist[u] + c)) PUSH(v);
        }
    }
}

void process(void) {
    dijkstra(1, adjBike, distFromOne);
    dijkstra(numNode, revAdjBike, distToN);
    dijkstra(destVinh, revAdjWalk, distToK);

    long long res = INF;
    FOR(u, 1, numNode) if (distFromOne[u] + distToK[u] <= limitVinh) minimize(res, distFromOne[u] + distToN[u]);
    cout << res << "\n";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    loadGraph();
    process();
    return 0;
}
