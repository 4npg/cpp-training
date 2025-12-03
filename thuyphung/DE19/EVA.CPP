// author : anphung >> npkly
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define fi first 
#define se second

const int64 inf = (1LL<<60);

int n, k;

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    file("EVA");
    cin>>n>>k;
    vector<int> exit(k);
    for (int i = 0; i < k; ++i) cin >> exit[i];

    int m; cin >> m;
    vector<vector<pair<int,int>>> a(n+1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb({v,w});
        a[v].pb({u,w});
    }

    vector<int64> d(n+1, inf);
    priority_queue<pair<int64,int>, vector<pair<int64,int>>, greater<pair<int64,int>>> q;

    for (int s : exit) {
        if (d[s] > 0) {
            d[s] = 0;
            q.push({0, s});
        }
    }

    while (!q.empty()) {
        auto top = q.top(); q.pop();
        int64 d = top.fi;
        int u = top.se;
        if (d != d[u]) continue;
        for (auto x : a[u]) {
            int v = x.fi;
            int w = x.se;
            if (d[v] > d + w) {
                d[v] = d + w;
                q.push({d[v], v});
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        if (d[i] >= inf/2) cout << -1;
        else cout << d[i];
        if (i < n) cout << ' ';
    }
    cerr << "\ntime elapsed: " << TIME << "s.\n";
}
