// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 200005
#define pli pair<int64, int>
#define inf (int64)4e18
#define fi first 
#define se second 
#define pb push_back

int n, m;
vector<pli> a[maxn];
int64 d[maxn];

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);


    cin>>n>>m;

    f0(i, 1, n)d[i] = inf;
    d[1] = 0;

    f0(i, 0, m-1){
        int u, v, w;
        cin>>u>>v>>w;
        a[u].pb({v, w});
        a[v].pb({u, w});
    }

    priority_queue<pli> q;
    q.push({-d[1], 1});

    while(q.size()){
        int64 du = -q.top().fi;
        int u = q.top().se;
        q.pop();
        if(du != d[u])continue;
        for(auto &p:a[u]){
            int v = p.fi;
            int64 w = p.se;

            if(d[u] + w < d[v]){
                d[v] = d[u] + w;
                q.push({-d[v], v});
            }
        }
    }

    cout<<d[n];
    cerr << "time elapsed: "<<TIME <<"s.\n";
}




