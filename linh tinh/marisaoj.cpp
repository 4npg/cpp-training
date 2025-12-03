// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back
#define maxn 100005
#define fi first
#define se second
int n, m, x, y;
vector<int> g[maxn];


int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>m>>x>>y;
    vector< vector<int> > d(n+1, vector<int>(2, -2));
    f0(i, 0, m-1){
        int u, v;
        cin>>u>>v;
        g[u].pb(v);
        g[v].pb(u);
    }

    queue< pair<int, int> > q;
    q.push({x, 0});
    d[x][0] = 0;
    while(!q.empty()){
        int u = q.front().fi;
        int k = q.front().se;
        q.pop();

        for(auto &v:g[u]){
            if(d[v][1-k] == -2){
                d[v][1-k] = d[u][k]+1;
                q.push({v, 1-k});
            }
        }
    }
    
    cout<<d[y][0]/2;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


