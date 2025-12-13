// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "giddy"
#define int64 long long
#define f0(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 100005
#define pb push_back
#define inf (int64)4e18
#define fi first
#define se second
#define pli pair<int64, int>
int n, m, k;
vector< pair<int, int> > a[maxn];
long long dn[50005], d2[50005];

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

     cin>>n>>m>>k;
    f0(i,0,m-1){
        int u,v,w; cin>>u>>v>>w;
        a[u].pb({v,w});
        a[v].pb({u,w});
    }

    f0(i,1,n) dn[i]=inf;
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    dn[n]=0;
    pq.push({0,n});
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop();
        int64 d = cur.fi; int u = cur.se;
        if(d != dn[u]) continue;
        for(auto &e: a[u]){
            int v = e.fi; int w = e.se;
            if(dn[v] > d + w){
                dn[v] = d + w;
                pq.push({dn[v], v});
            }
        }
    }

    f0(i,1,n) d2[i]=inf;
    priority_queue<pli, vector<pli>, greater<pli>> pq2;
    f0(i,1,k){
        int p; int64 c; cin>>p>>c;
        int64 R = c - dn[p];
        int64 val = -R;
        if(val < d2[p]){
            d2[p] = val;
            pq2.push({d2[p], p});
        }
    }

    while(!pq2.empty()){
        auto cur = pq2.top(); pq2.pop();
        int64 d = cur.fi; int u = cur.se;
        if(d != d2[u]) continue;
        for(auto &e: a[u]){
            int v = e.fi; int w = e.se;
            if(d2[v] > d + w){
                d2[v] = d + w;
                pq2.push({d2[v], v});
            }
        }
    }

    f0(i,1,n){
        if(d2[i] <= dn[i]) cout<<1<<"\n";
        else cout<<0<<"\n";
    }

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
