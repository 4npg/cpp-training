// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define maxn 200005

int n, q;
int64 t[maxn*4+50], lazyA[maxn*4+50], lazyB[maxn*4+50];

int64 sumIdx(int l, int r){
    return 1LL*(l+r)*(r-l+1)/2;
}

void apply(int id, int l, int r, int64 a, int64 b){
    t[id] += a * sumIdx(l, r) + b * (r - l + 1);
    lazyA[id] += a;
    lazyB[id] += b;
}

inline void push(int id, int l, int r){
    if (l == r) return; 
    if(lazyA[id] == 0 && lazyB[id] == 0) return;
    int mid = (l+r)/2;
    apply(id*2, l, mid, lazyA[id], lazyB[id]);
    apply(id*2+1, mid+1, r, lazyA[id], lazyB[id]);

    lazyA[id] = lazyB[id] = 0;
}

void build(int id, int l, int r, vector<int64>& a){
    if(l == r){
        t[id] = a[l];
        return;
    }
    int mid = (l+r)/2;
    build(id*2, l, mid, a);
    build(id*2+1, mid+1, r, a);
    t[id] = t[id*2] + t[id*2+1];
}

void getupdate(int id, int l, int r, int u, int v, int64 a, int64 b){
    if(r < u || v < l) return;

    if(u <= l && r <= v){
        apply(id, l, r, a, b);
        return;
    }

    push(id, l, r);

    int mid = (l+r)/2;
    getupdate(id*2, l, mid, u, v, a, b);
    getupdate(id*2+1, mid+1, r, u, v, a, b);

    t[id] = t[id*2] + t[id*2+1];
}

int64 get(int id, int l, int r, int u, int v){
    if(v < l || r < u) return 0;

    push(id, l, r);

    if(u <= l && r <= v) return t[id];

    int mid = (l+r)/2;
    return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

void update(int l, int r){
    int64 a = 1;
    int64 b = -(l-1);
    getupdate(1, 1, n, l, r, a, b);
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n;
	vector<int64> a(n+1);
    for (int i = 1; i <= n; i++)cin>>a[i];

    build(1, 1, n, a);

    cin >> q;
    while(q--){
        int type, l, r;
        cin >> type >> l >> r;

        if(type == 1) update(l, r);
        else cout << get(1, 1, n, l, r) << "\n";
    }
	cerr << "time elapsed: "<<TIME <<"s.\n";
}