// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file ""
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define all(a) (a).begin(),(a).end()

int n,m,l;
vector< pair<int,int> > key;

struct DSU {
    int n;
    vector<int> p,sz;
    DSU(int n = 0){
        init(n);
    }

    void init(int nn){
        n = nn;
        p.assign(n+1,0);
        sz.assign(n+1,1);
        iota(all(p),0);
    }
    int find(int x){
        return p[x] == x ? x : p[x] = find(p[x]);
    }
    void unite(int a,int b){
        a = find(a);
        b = find(b);
        if(a==b)return ;
        if(sz[a]<sz[b])swap(a,b);
        p[b]=a;
        sz[a]+=sz[b];
    }
};

bool cmp(int a,int b){
    return key[a]<key[b];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n>>m>>l;
    DSU d1(n),d2(n);
    f0(i,0,m-1){
        int u,v;cin>>u>>v;
        d1.unite(u,v);
    }
    f0(i,0,l-1){
        int x,y;cin>>x>>y;
        d2.unite(x,y);
    }

    key.resize(n+1);

    f0(i,1,n){
        key[i] = {d1.find(i),d2.find(i)};
    }

    vector<int> ord(n);
    f0(i,0,n-1){
        ord[i] = i+1;
    }
    sort(all(ord),cmp);

    vector<int> ans(n+1);
    for(int i=0,j;i<n;i=j){
        j=i+1;
        while(j<n&&key[ord[i]]==key[ord[j]])++j;
        int siz = j-i;
        f0(t,i,j-1)ans[ord[t]]=siz;
    }
    f0(i,1,n){
        cout<<ans[i]<<(i<n?' ':'\n');
    }
    cerr << "time elapsed: "<<TIME <<"s.\n";
}
