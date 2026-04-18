#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9+7;
const int mod = 1e9+7;
const int maxn = 1e6+5;

template <class X, class Y> bool maximize(X &a, Y b){
    if(a < b) return a = b, true;
    return false;
}

template <class X, class Y> bool minimize(X &a, Y b){
    if(a > b) return a= b, true;
    return false;
}

long long a[maxn], t[maxn*4];
int n, q;

// void build(int id, int l, int r){
//     if(l == r){
//         t[id] = a[l];
//         return ;
//     }

//     int mid = (l+r)/2;
//     build(id*2, l, mid);
//     build(id*2+1, mid+1, r);

//     t[id] = t[id*2] + t[id*2+1];
// }


struct segtree{
    int n;
    vector<long long> t;

    segtree(int _n){
        n = _n;
        t.resize(4*n+5);
    }

    inline void update(int id, int l, int r, int p, long long x){
        if(l == r){
            t[id] = x;
            return;
        }

        int mid = (l + r)/2;
        if(p <= mid)update(id*2, l, mid, p, x);
        else update(id*2+1, mid+1, r, p, x);

        t[id] = max(t[id*2], t[id*2+1]);
    }

    long long get(int id, int l, int r, int u, int v){
        if(v < l || r < u) return -inf;
        if(u <= l && r <= v)return t[id];

        int mid = (l + r)/2;
        long long tl = get(id*2, l, mid, u, v);
        long long tr = get(id*2+1, mid+1, r, u, v);

        return max(tl, tr);
    }

};


// inline void update(int id, int l, int r, int p, long long x){
//     if(l == r){
//         t[id] = x;
//         return;
//     }
//     int mid = (l+r)/2;
//     if(p <= mid){
//         update(id*2, l, mid, p, x);
//     } else update(id*2+1, mid+1, r, p, x);

//     t[id] = max(t[id*2], t[id*2+1]);
// }

// long long get(int id, int l, int r, int u, int v){
//     if(v < l || r < u) return -inf;
//     if(u <= l && r <= v)return t[id];

//     int mid = (l + r)/2;
//     long long tl = get(id*2, l, mid, u, v);
//     long long tr = get(id*2+1, mid+1, r, u, v);

//     return max(tl, tr);
// }

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    // int bla = uniform_int_distribution<int>(1, 100)(rng);

    cin >> n;

    segtree sg(n);
    
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sg.update(1, 1, n, i, a[i]);
    }

    cin >> q;
    while(q--){
        int op, l, r;
        cin >> op >> l >> r;

        if(op == 1){
            sg.update(1, 1, n, l, r);
        } else cout << sg.get(1, 1, n, l, r)<<'\n';
    }

    cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}