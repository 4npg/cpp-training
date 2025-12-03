// author : anphung
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
const int64 mod = 1000000007LL;
const int maxn = 100005;

int n, m;
int64 t[maxn * 4];
int64 lazy[maxn * 4];

inline int64 mulmod(int64 a, int64 b){
    return (a % mod) * (b % mod) % mod;
}

void build(int id, int l, int r){
    lazy[id] = 1;
    if(l == r){
        t[id] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);
    t[id] = (t[id<<1] + t[id<<1|1]) % mod;
}

inline void push(int id, int l, int r){
    if(lazy[id] == 1) return;
    if(l == r){
        lazy[id] = 1;
        return;
    }
    int lc = id<<1, rc = id<<1|1;
    t[lc] = mulmod(t[lc], lazy[id]);
    lazy[lc] = mulmod(lazy[lc], lazy[id]);

    t[rc] = mulmod(t[rc], lazy[id]);
    lazy[rc] = mulmod(lazy[rc], lazy[id]);

    lazy[id] = 1;
}

void update(int id, int l, int r, int u, int v, int64 x){
    if(v < l || r < u) return;
    if(u <= l && r <= v){
        t[id] = mulmod(t[id], x);
        lazy[id] = mulmod(lazy[id], x);
        return;
    }
    int mid = (l + r) >> 1;
    push(id, l, r); 
    update(id<<1, l, mid, u, v, x);
    update(id<<1|1, mid+1, r, u, v, x);
    t[id] = (t[id<<1] + t[id<<1|1]) % mod;
}

int64 get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;
    if(u <= l && r <= v) return t[id];
    int mid = (l + r) >> 1;
    push(id, l, r);
    int64 tl = get(id<<1, l, mid, u, v);
    int64 tr = get(id<<1|1, mid+1, r, u, v);
    return (tl + tr) % mod;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    build(1, 1, n);
    while(m--){
        int type, l, r;
        cin >> type >> l >> r;
        if(type == 1){
            int64 v; cin >> v;
            update(1, 1, n, l, r, v % mod);
        } else {
            cout << get(1, 1, n, l, r) << '\n';
        }
    }
    cerr << "time elapsed: " << TIME << "s.\n";
}
