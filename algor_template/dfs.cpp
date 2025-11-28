// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 100005
#define pb push_back

int n,m;
int d[maxn];
bool vis[maxn];
vector<int> a[maxn];

void dfs(int s){
    vis[s] = 1;
    for(auto &v:a[s]){
        if(!vis[v]){
            d[v] = d[s] + 1;
            dfs(v);
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
    memset(d, -1, sizeof(d));
    d[1] = 0;

    dfs(1);
    f0(i,2,n){
        cout<<d[i]<<" ";
    }
    cerr << "time elapsed: "<<TIME <<"s.\n";
}





