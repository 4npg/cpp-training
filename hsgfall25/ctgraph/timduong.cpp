// author : anphung >> npkly
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int n, m, S, T;
vector<int> g[100005];
int parent[100005];
bool vis[100005];

bool dfs(int u){
    vis[u] = 1;
    if(u == T) return 1;
    for(int v : g[u]){
        if(!vis[v]){
            parent[v] = u;
            if(dfs(v)) return 1;
        }
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m >> S >> T;
    for(int i=0;i<m;i++){
        int u,v; cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    parent[S] = -1;
    if(!dfs(S)){
        cout << -1;
        return 0;
    }
    vector<int> path;
    for(int v=T; v!=-1; v=parent[v]) path.pb(v);
    reverse(path.begin(), path.end());
    for(int x : path) cout<<x<<" ";
}
