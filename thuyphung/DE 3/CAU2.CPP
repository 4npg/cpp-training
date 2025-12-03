#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
const int maxn = 10010;
vector<int> a[maxn];
int cau,cnt;
int id[maxn],low[maxn];

void dfs(int u,int p){
    id[u] = low[u] = cnt++;
    for(int v:a[u]){
        if(v!=p){
            if(!id[v]){
                dfs(v,u);
                low[u] = min(low[u],low[v]);
                if(id[v] == low[v])cau++;
            }else{
                low[u] = min(low[u],id[v]);
            }
        }
    }
}
int main(){
    fast;
    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }
    for(int i=0;i<m;i++){
        if(!id[i]){
            dfs(i,i);
        }
    }
    cout<<cau;
}
