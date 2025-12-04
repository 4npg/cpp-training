// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define inf (int64)2e18
#define maxn 200005

int n, q;
int64 t1[maxn*4], t2[maxn*4];
int64 a[maxn];
int64 a1[maxn], a2[maxn];

void build1(const int64 a[], int id, int l, int r){
    if(l == r){
        t1[id] = a[l];
        return;
    }

    int mid = (l+r)/2;
    build1(a, 2*id, l, mid);
    build1(a, 2*id+1, mid+1, r);
    t1[id] = min(t1[id*2], t1[id*2+1]);
}

void build2(const int64 a[], int id, int l, int r){
    if(l == r){
        t2[id] = a[l];
        return;
    }

    int mid = (l+r)/2;
    build2(a, id*2, l, mid);
    build2(a, id*2+1, mid+1, r);
    t2[id] = min(t2[id*2], t2[id*2+1]);
}

void update1(int id, int l, int r, int p, int64 v){
    if(l == r){
        t1[id] = v;
        return;
    }

    int mid = (l+r)/2;
    if(p<=mid)update1(id*2, l, mid, p, v);
    else update1(id*2+1, mid+1, r, p, v);

    t1[id] = min(t1[id*2], t1[id*2+1]);
}

void update2(int id, int l, int r, int p, int64 v){
    if(l == r){
        t2[id] = v;
        return;
    }

    int mid = (l+r)/2;
    if(p<=mid)update2(id*2, l, mid, p, v);
    else update2(id*2+1, mid+1, r, p, v);

    t2[id] = min(t2[id*2], t2[id*2+1]);
}

int64 get1(int id, int l, int r, int u, int v){
    if(v<l || r<u)return inf;
    if(u<=l && r<=v){
        return t1[id];
    }

    int mid = (l+r)/2;
    int64 tl = get1(id*2, l, mid, u, v);
    int64 tr = get1(id*2+1, mid+1, r, u, v);

    return min(tl, tr);
}

int64 get2(int id, int l, int r, int u, int v){
    if(v<l || r<u)return inf;
    if(u<=l && r<=v){
        return t2[id];
    }

    int mid = (l+r)/2;
    int64 tl = get2(id*2, l, mid, u, v);
    int64 tr = get2(id*2+1, mid+1, r, u, v);

    return min(tl, tr);
}
int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>q;
    f0(i, 1, n){
        cin>>a[i];
        a1[i] = a[i] + i;
        a2[i] = a[i] - i;
    }

    build1(a1, 1, 1, n);
    build2(a2, 1, 1, n);

    while(q--){
        int type, i;
        cin>>type>>i;

        if(type == 1){
            int64 x; cin>>x;
            a[i] = x;
            update1(1, 1, n, i, x+i);
            update2(1, 1, n, i, x-i);
        }else {
            int64 cr = get1(1, 1, n, i, n) - i;
            int64 cl = get2(1, 1, n, 1, i-1) + i;
            cout<<min(cr, cl)<<'\n';
        }
    }

    cerr << "time elapsed: "<<TIME <<"s.\n";
}
