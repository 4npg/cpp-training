// author : anphung
#include<bits/stdc++.h>
using namespace std;

#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b); ++i)
#define fd(i,a,b) for(int i = (a); i >= (b); --i)

#define maxn 100005
#define inf (long long)4e18

int n, m;
long long a[maxn];

map<long long,int> t[maxn * 4];

void build(int id, int l, int r){
    if(l == r){
        t[id][a[l]]++;
        return;
    }
    int mid = (l + r) >> 1;
    build(id<<1, l, mid);
    build(id<<1|1, mid+1, r);

    t[id] = t[id<<1|1];
    for(auto &p : t[id<<1]){
        t[id][p.first] += p.second;
    }
}

inline void add(map<long long,int> &mp, long long x){
    mp[x]++;
}

inline void remove_one(map<long long,int> &mp, long long x){
    auto it = mp.find(x);
    if(it == mp.end()) return;
    it->second--;
    if(it->second == 0) mp.erase(it);
}

void update(int id, int l, int r, int i, long long old, long long val){
    if(i < l || i > r) return;

    if(l == r){
        t[id].clear();
        t[id][val]++;
        return;
    }

    int mid = (l + r) >> 1;
    update(id<<1, l, mid, i, old, val);
    update(id<<1|1, mid+1, r, i, old, val);

    remove_one(t[id], old);
    add(t[id], val);
}

long long get(int id, int l, int r, int u, int v, long long k){
    if(r < u || v < l) return inf;
    if(u <= l && r <= v){
        auto it = t[id].lower_bound(k);
        if(it == t[id].end()) return inf;
        return it->first;
    }
    int mid = (l + r) >> 1;
    return min(
        get(id<<1, l, mid, u, v, k),
        get(id<<1|1, mid+1, r, u, v, k)
    );
}

con_meo_dua_leo(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    f0(i,1,n) cin >> a[i];

    build(1, 1, n);

    while(m--){
        int type; cin >> type;
        if(type == 1){
            int i; long long v;
            cin >> i >> v;
            update(1, 1, n, i, a[i], v);
            a[i] = v;
        }else{
            int l, r; long long k;
            cin >> l >> r >> k;
            long long ans = get(1, 1, n, l, r, k);
            cout << (ans == inf ? -1 : ans) << '\n';
        }
    }

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}
