// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define maxn 100005

int n,m;

int64 t[maxn*4], lazy[maxn*4];

void build(int id, int l, int r){
    t[id] = 0;
    lazy[id] = 0;
    if(l==r) return;
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}

inline void apply(int id, int64 v){
    t[id] |= v;
    lazy[id] |= v;
}

void push(int id){
    if(lazy[id]){
        apply(id*2, lazy[id]);
        apply(id*2+1, lazy[id]);
        lazy[id] = 0;
    }
}

void update(int id, int l, int r, int u, int v, int64 mask){
    if(v<l || r<u) return;
    if(u<=l && r<=v){
        apply(id, mask);
        return;
    }
    push(id);
    int mid=(l+r)/2;
    update(id*2,l,mid,u,v,mask);
    update(id*2+1,mid+1,r,u,v,mask);
    t[id] = t[id*2] & t[id*2+1];
}

int64 get(int id, int l, int r, int u, int v){
    if(v<l || r<u) return (int64)(-1); 
    if(u<=l && r<=v) return t[id];
    push(id);
    int mid=(l+r)/2;
    int64 tl = get(id*2,l,mid,u,v);
    int64 tr = get(id*2+1,mid+1,r,u,v);
    return tl & tr;
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>n>>m;
    build(1,1,n);

    while(m--){
        int type;
        cin>>type;
        if(type==1){
            int l,r; int64 v;
            cin>>l>>r>>v;
            update(1,1,n,l,r,v);
        }else{
            int l,r;
            cin>>l>>r;
            cout<<get(1,1,n,l,r)<<'\n';
        }
    }

    cerr << "time elapsed: "<<TIME <<"s.\n";
}
