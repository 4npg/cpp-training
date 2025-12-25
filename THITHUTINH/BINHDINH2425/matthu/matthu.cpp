// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i=(a); i<=(b);++i)
#define fd(i,a,b) for(int i=(a); i>=(b);--i)
#define file "matthu"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 100005

int n, q;
int64 a[maxn];

struct node{
    int64 sum;
    int64 mx;
} t[maxn*4];

node merge(const node &l, const node &r){
    return {l.sum + r.sum, max(l.mx, r.mx)};
}

void build(int id, int l, int r){
    if(l == r){
        t[id] = {a[l], a[l]};
        return;
    }

    int mid = (l+r)/2;

    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    t[id] = merge(t[id*2], t[id*2+1]);
}

void update(int id, int l, int r, int p, int64 x){
    if(l == r){
        t[id] = {x, x};
        return;
    }

    int mid = (l+r)/2;
    if(p<=mid)update(id*2, l, mid, p, x);
    else update(id*2+1, mid+1, r, p, x);

    t[id] = merge(t[id*2], t[id*2+1]);
}

void updatemod(int id, int l, int r, int u, int v, int64 w){
    if(v<l || r<u)return;
    if(t[id].mx < w)return;

    if(l == r){
        t[id].sum %= w;
        t[id].mx = t[id].sum;
        return;
    }

    int mid = (l+r)/2;

    updatemod(id*2, l, mid, u, v, w);
    updatemod(id*2+1, mid+1, r, u, v, w);

    t[id] = merge(t[id*2], t[id*2+1]);
}

int64 get(int id, int l, int r, int u, int v){
    if(v<l || r<u)return 0;
    if(u<=l && r<=v)return t[id].sum;

    int mid = (l+r)/2;

    int64 tl = get(id*2, l, mid, u, v);
    int64 tr = get(id*2+1, mid+1, r, u, v);

    return tl + tr;
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);

    cin>>n>>q;
    f0(i, 1, n)cin>>a[i];

    build(1, 1, n);

    while(q--){
        int type; cin>>type;

        if(type == 1){
            int l, r; cin>>l>>r;

            cout<<get(1, 1, n, l, r)<<'\n';
        }

        else if(type == 2){
            int l, r; int64 w;
            cin>>l>>r>>w;

            updatemod(1, 1, n, l, r, w);
        }

        else {
            int p; int64 x;
            cin>>p>>x;
            update(1, 1, n, p, x);
        }
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
