// author : anphung
#include<bits/stdc++.h>
using namespace std;

#define int64 long long
const int64 INF = (int64)4e18;
const int MOD1 = 1000000007;
const int MOD2 = 1000000009;

int n, m;
vector<pair<int,int>> adj[300005];
int64 d1[300005], dn[300005];

void dijkstra(int s, int64 d[]){
    fill(d+1, d+n+1, INF);
    priority_queue<pair<int64,int>, vector<pair<int64,int>>, greater<>> pq;
    d[s] = 0;
    pq.push({0, s});
    while(!pq.empty()){
        long long du = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if(du != d[u]) continue;
        for(auto &p: adj[u]){
            int v = p.first;
            long long w = p.second;
            if(d[v] > du + w){
                d[v] = du + w;
                pq.push({d[v], v});
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >> u >> v >> w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }

    dijkstra(1, d1);
    dijkstra(n, dn);

    int64 D = d1[n];

    vector<vector<int>> dag(n+1);
    vector<int> indeg(n+1, 0);

    for(int u=1;u<=n;u++){
        for(auto &p: adj[u]){
            int v = p.first; long long w = p.second;
            if(d1[u] + w + dn[v] == D){
                dag[u].push_back(v);
                indeg[v]++;
            }
        }
    }

    vector<int> topo;
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(indeg[i]==0) q.push(i);
    }
    while(!q.empty()){
        int u = q.front(); q.pop();
        topo.push_back(u);
        for(int v: dag[u]){
            if(--indeg[v]==0) q.push(v);
        }
    }

    vector<int> c1(n+1,0), c2(n+1,0);
    c1[1] = c2[1] = 1;

    for(int u: topo){
        for(int v: dag[u]){
            c1[v] = (c1[v] + c1[u]) % MOD1;
            c2[v] = (c2[v] + c2[u]) % MOD2;
        }
    }

    vector<int> d1n(n+1,0), d2n(n+1,0);
    d1n[n] = d2n[n] = 1;

    reverse(topo.begin(), topo.end());
    for(int u: topo){
        for(int v: dag[u]){
            d1n[u] = (d1n[u] + d1n[v]) % MOD1;
            d2n[u] = (d2n[u] + d2n[v]) % MOD2;
        }
    }

    int total1 = c1[n], total2 = c2[n];

    vector<int> ans;
    for(int i=2;i<n;i++){
        if( (int64)c1[i]*d1n[i]%MOD1 == total1 &&
            (int64)c2[i]*d2n[i]%MOD2 == total2 ){
            continue; 
        }
        ans.emplace_back(i);
    }

    cout << ans.size() << '\n';
    for(int x: ans) cout << x << '\n';
}
