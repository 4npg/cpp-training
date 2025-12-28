// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
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
#define inf (int64)4e18
#define pb push_back

int n, U, V, p[maxn], d[maxn], dd[maxn];
int f[maxn], g[maxn];

vector<int> a[maxn];

void dfs(int u){
    d[u] = 1;

    if(u == V)dd[u] = 1;
    for(int v, i=0; i<a[u].size(); ++i){
        v = a[u][i];
        if(v == p[u])continue;
        p[v] = u;
    }
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
