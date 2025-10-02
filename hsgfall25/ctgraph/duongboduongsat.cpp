// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

struct DSU {
    int n;
    vector<int> p, sz;
    DSU(int n=0){ 
        init(n); 
    }

    void init(int _n){
        n=_n;
        p.assign(n+1,0);
        sz.assign(n+1,1);
        iota(p.begin(), p.end(), 0);
    }

    int find(int x){
        return p[x]==x? x : p[x]=find(p[x]);
    }

    void unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        p[b]=a; sz[a]+=sz[b];
    }
    
};

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);

    int n,m,l;
    cin>>n>>m>>l;

    DSU d1(n), d2(n);

    f0(i,0,m-1){
        int u,v; cin>>u>>v;
        d1.unite(u,v);
    }
    f0(i,0,l-1){
        int x,y; cin>>x>>y;
        d2.unite(x,y);
    }

    vector<int64> key(n+1);
    key[0]=0;
    unordered_map<int64,int> cnt;
    cnt.reserve(n*2);
    f0(i,1,n){
        int64 k = ((int64)(d1.find(i))<<32*1ll)|(int64)(d2.find(i));
        key[i]=k;
        cnt[k]++;
    }

    f0(i,1,n){
        cout<<cnt[key[i]];
        if(i<n)cout<<' ';
    }
    cerr << "time elapsed: "<<TIME <<"s.\n";
}
