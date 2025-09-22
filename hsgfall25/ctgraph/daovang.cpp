// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define fast ios::sync_with_stdio(0); cin.tie(0);
#define f0(i,a,b) for(int (i)=(a); i<=(b); ++i)
#define pb push_back

const int maxn=1e5+5;
int n,m,q;
vector<int> a(maxn);
vector<vector<int>> g(maxn);
vector<int> id(maxn);
vector<char> used(maxn);

struct TP{int sl; int64 tong; int max_vang;};
vector<TP> tp;

void dfs(int u,int comp){
    used[u]=1;
    id[u]=comp;
    tp[comp].sl++;
    tp[comp].tong+=a[u];
    tp[comp].max_vang=max(tp[comp].max_vang,a[u]);
    for(int v:g[u]) if(!used[v]) dfs(v,comp);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    f0(i,1,n) cin>>a[i];
    f0(i,1,m){
        int u,v;cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int cnt=0;
    f0(i,1,n) if(!used[i]){
        tp.pb({0,0,0});
        dfs(i,cnt++);
    }
    cin>>q;
    while(q--){
        int x;cin>>x;
        auto &res=tp[id[x]];
        cout<<res.sl<<" "<<res.tong<<" "<<res.max_vang<<"\n";
    }
}
