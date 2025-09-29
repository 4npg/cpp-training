// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define pb push_back
#define ump unordered_map
#define ust unordered_set
#define fi first
#define se second
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0);

    int m;
    int64 S, T;
    cin >> m >> S >> T;
    vector<pair<int64,int64>> edges(m);
    f0(i,0,m-1) cin >> edges[i].fi >> edges[i].se;

    ump<int64, vector<int64>> g;
    ust<int64> reachable;
    queue<int64> q;

    reachable.insert(S);
    q.push(S);

    f0(i,0,m-1){
        int64 u = edges[i].fi, v = edges[i].se;
        g[u].pb(v);

        if(reachable.count(u) && !reachable.count(v)){
            reachable.insert(v);
            q.push(v);
        }

        while(!q.empty()){
            int64 x = q.front(); q.pop();
            for(int64 y : g[x]){
                if(!reachable.count(y)){
                    reachable.insert(y);
                    q.push(y);
                }
            }
        }

        if(reachable.count(T)){
            cout << i+1;
            cerr << "time elapsed: "<<TIME <<"s.\n";
            return 0;
        }
    }

    cout << -1;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}
