// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back
#define maxn 200005

int n,m;
vector<int> a[maxn];
bool vis[maxn];
int parent[maxn];
int d[maxn];

void bfs(int s){
    vis[s] = true;
    parent[s] = s;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        int u = q.front();q.pop();
        vis[u] = true;
        for(auto &v:a[u]){
            if(!vis[v]){
                d[v] = d[u] + 1;
                q.push(v);
                vis[v] = true;
                parent[v] = u;
            }
        }
    }
}


int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>m;
    f0(i,0,m-1){
        int u,v;
        cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }    
    d[1] = 0;
    bfs(1);

    vector<int> path;
    int cur = n;
    while(true){
        path.pb(cur);
        if(cur==1)break;
        else cur = parent[cur];
    }
    reverse(path.begin(),path.end());
    cout<<d[n]<<'\n';
    for(auto &x:path)cout<<x<<" ";
    cerr << "time elapsed: "<<TIME <<"s.\n";
}





