// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

const int maxn=1e5+5;
vector<int> a[maxn];
bool vis[maxn];

void bfs(int start, int &cnt){
    queue<int> q;
    q.push(start);
    vis[start]=true;
    cnt=0;
    while(!q.empty()){
        int u=q.front(); q.pop();
        cnt++;
        for(int v:a[u]){
            if(!vis[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n,m; cin>>n>>m;
    f0(i,0,m-1){
        int u,v; cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    int64 res=0;
    f0(i,1,n){
        if(!vis[i]){
            int sz;
            bfs(i,sz);
            res+=1LL*sz*(sz-1)/2;
        }
    }
    cout<<res;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}
