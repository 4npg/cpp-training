// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 200005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)
#define pli pair<long long, int>

int n, m, k;

struct edge{
    int u, v; 
    long long w;

    edge(int _u, int _v, long long _w) : u(_u), v(_v), w(_w) {}

    friend bool operator < (const edge &a, const edge &b){
        return a.w > b.w;
    }
};

vector<edge> e;

struct graph{
    vector< pair<int, long long> > ke[maxn];
    long long d[maxn];


    void addEdge(int u, int v, long long w){
        ke[u].emplace_back(v, w);
        ke[v].emplace_back(u, w);
    }

    void dijkstra(int s){

        f0(i, 1, n)d[i] = inf;

        d[s] = 0;

        priority_queue<pli, vector<pli>, greater<pli>> pq;
        pq.push({0LL, s});

        while(pq.size()){
            int u = pq.top().second; long long du = pq.top().first; pq.pop();

            if(d[u] != du) continue;

            for(auto &e:ke[u]){
                int v = e.first; long long w = e.second;
                if(d[v] > d[u] + w){
                    d[v] = d[u] + w;
                    pq.push({d[v], v});
                }
            }
        }
    }

} g;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>m>>k;
    f0(i, 0, m-1){
        int u, v; cin>>u>>v;
        long long w; cin>>w;
        g.addEdge(u, v, w);
        e.emplace_back(u, v, w);
    }

    sort(e.begin(), e.end());

    f0(i, 0, k-1){
        int u = e[i].u, v = e[i].v;
        long long w = e[i].w;

        for(auto &p:g.ke[u])if(p.first == v && p.second == w)p.second = 0;
        for(auto &p:g.ke[v])if(p.first == u && p.second == w)p.second = 0;
    }

    g.dijkstra(1);

    cout<<(g.d[n]!=inf?g.d[n]:-1);
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}