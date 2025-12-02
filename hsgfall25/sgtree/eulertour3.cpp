/*
    www.youtube.com/YugiHackerChannel
    linktr.ee/YugiHacker
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 200005
using namespace std;
int n, q;
vector <int> g[maxn];
int in[maxn], out[maxn], sz[maxn], cnt, c[maxn];
long long t[maxn * 4];
/// out[u] = in[u] + sz[u] - 1
void update (int id, int l, int r, int p, int v) {
    if (l == r) return void(t[id] = v);
    int mid = (l + r) / 2;
    if (p <= mid) update(id*2, l, mid, p, v);
    else update(id*2+1, mid+1, r, p, v);
    t[id] = t[id*2] + t[id*2+1];
}
long long get(int id, int l, int r, int u, int v) {
    if (r < u || v < l) return 0;
    if (u <= l && r <= v) return t[id];
    int mid = (l + r) / 2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}
void dfs(int u, int p) {
    in[u] = ++cnt;
    for (int v:g[u]) if (v != p) dfs(v, u);
    out[u] = cnt;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> q;
    for (int u=1; u<=n; u++) cin >> c[u];
    for (int i=1; i<n; i++) {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1, -1);
    for (int u=1; u<=n; u++) update(1, 1, n, in[u], c[u]);
    while (q--) {
        int type, u, v;
        cin >> type >> u;
        if (type == 1) {
            cin >> v;
            update(1, 1, n, in[u], v);
        }
        else cout << get(1, 1, n, in[u], out[u]) << '\n';
    }
}