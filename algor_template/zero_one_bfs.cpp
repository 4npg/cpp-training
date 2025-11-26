#include <bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int INF = 1e9;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m; cin>>n>>m;
    vector<vector<pair<int,int>>> adj(n+1);
    for(int i=0;i<m;i++){
        int u,v,w; cin>>u>>v>>w; // w in {0,1}
        adj[u].push_back({v,w});
        // if undirected: adj[v].push_back({u,w});
    }
    deque<int> dq;
    vector<int> dist(n+1, INF);
    int s=1; dist[s]=0; dq.push_front(s);
    while(!dq.empty()){
        int u=dq.front(); dq.pop_front();
        for(auto [v,w]: adj[u]){
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
                if(w==0) dq.push_front(v); else dq.push_back(v);
            }
        }
    }
    return 0;
}
