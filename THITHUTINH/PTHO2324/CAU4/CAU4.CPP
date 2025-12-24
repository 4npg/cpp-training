// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define maxn 200005
#define file "CAU4"
#define pb push_back

int n;
vector<int> a[maxn];
int u0, v0;
vector<int> path;
bool f = false;

void dfsp(int u, int p){
    if(f) return;
    path.pb(u);
    if(u == v0){
        f = true;
        return;
    }
    for(int v:a[u]){
        if(v == p) continue;
        dfsp(v, u);
        if(f) return;
    }
    path.pop_back();
}

int dfsd(int u, int p, int ban){
    int res = 1;
    for(int v:a[u]){
        if(v == p || v == ban) continue;
        res = max(res, dfsd(v, u, ban) + 1);
    }
    return res;
}

youngboiz_nobug(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    cin >> n;
    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        a[u].pb(v);
        a[v].pb(u);
    }

    cin >> u0 >> v0;

    if(u0 == v0){
        cout << 1;
        return 0;
    }

    dfsp(u0, -1);

    int nxu = path[1];
    int prev = path[path.size()-2];

    int dtom = dfsd(u0, -1, nxu);
    int danna = dfsd(v0, -1, prev);

    cout << max(dtom, danna);
}
