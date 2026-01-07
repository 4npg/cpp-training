// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//    return l+rng()%(r-l+1);
//}

#define maxn 200005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e3+7)

struct Fibonacci {
    vector<vector<long long>> mat;

    Fibonacci() {
        mat = {{1, 1}, {1, 0}};
    }

    vector<vector<long long>> mul(const vector<vector<long long>> &a, const vector<vector<long long>> &b) {
        vector<vector<long long>> c(2, vector<long long>(2));
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                    c[i][j] = (c[i][j] + a[i][k]*b[k][j]) % mod;
        return c;
    }

    vector<vector<long long>> ipow(vector<vector<long long>> a, long long b) {
        vector<vector<long long>> res = {{1, 0}, {0, 1}};
        while(b) {
            if(b & 1) res = mul(res, a);
            a = mul(a, a);
            b >>= 1;
        }
        return res;
    }

    long long getn(long long n) {
        if(n==0) return 0;
        vector<vector<long long>> res = ipow(mat, n-1);
        return res[0][0];
    }
} fib;

int n, q;

struct SegmentTree {
    long long t[maxn*4], lazy[maxn*4];

    void push(int id, int l, int r){
        if(!lazy[id]) return;
        t[id] += lazy[id]*(r-l+1);
        if(l!=r){
            lazy[id<<1] += lazy[id];
            lazy[id<<1|1] += lazy[id];
        }
        lazy[id] = 0;
    }

    void update(int id, int l, int r, int u, int v, long long val){
        push(id,l,r);
        if(v<l || r<u) return;
        if(u<=l && r<=v){
            lazy[id] += val;
            push(id,l,r);
            return;
        }
        int mid=(l+r)>>1;
        update(id<<1,l,mid,u,v,val);
        update(id<<1|1,mid+1,r,u,v,val);
        t[id]=t[id<<1]+t[id<<1|1];
    }

    long long get(int id, int l, int r, int u, int v){
        push(id,l,r);
        if(v<l || r<u) return 0;
        if(u<=l && r<=v) return t[id];
        int mid=(l+r)>>1;
        return get(id<<1,l,mid,u,v)+get(id<<1|1,mid+1,r,u,v);
    }
} seg;


struct Fenwick {
    int n;
    long long bit1[maxn], bit2[maxn];

    void init(int _n){
        n=_n;
        memset(bit1,0,sizeof(bit1));
        memset(bit2,0,sizeof(bit2));
    }

    void add(long long bit[], int i, long long v){
        for(; i<=n; i+=i&-i)
            bit[i]+=v;
    }

    long long sum(long long bit[], int i){
        long long s=0;
        for(; i>0; i-=i&-i)
            s+=bit[i];
        return s;
    }

    void upd(int l, int r, long long val){
        add(bit1,l,val);
        add(bit1,r+1,-val);
        add(bit2,l,val*(l-1));
        add(bit2,r+1,-val*r);
    }

    long long pre(int x){
        return sum(bit1,x)*x - sum(bit2,x);
    }

    long long get(int l, int r){
        return pre(r)-pre(l-1);
    }
} fw;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>q;
    fw.init(n);

    while(q--){
        int type, l, r; cin>>type>>l>>r;

        if(type == 1){
            long long k; cin>>k;
            k = fib.getn(k);
            fw.upd(l, r, k);
        }else{
            cout<<fw.get(l, r)<<'\n';
        }
    }

    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
