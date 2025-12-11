// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file "LATGACH"
#define all(a) (a).begin(), (a).end()
#define maxn 100005
#define fi first 
#define se second

int n;
int64 x[maxn], y[maxn], d[maxn], c[maxn];
int64 x1[maxn], x2[maxn], ymot[maxn], y2[maxn];

struct DSU{
    vector<int> p;
    DSU(int n=0){
        p.resize(n);
        iota(all(p),0);
    }

    int find(int x){
        return p[x]==x?x:p[x]=find(p[x]);
    }

    void Uni(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b)p[b] = a;
    }
};

bool touch(int i, int j){
    return max(x1[i], x1[j])<=min(x2[i], x2[j]) && max(ymot[i], ymot[j])<=min(y2[i], y2[j]);
}

int32_t main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n;
    f0(i, 0, n-1)cin>>x[i]>>y[i]>>d[i]>>c[i];

    f0(i, 0, n-1){
        x1[i] = x[i];
        x2[i] = x[i] + d[i];
        ymot[i] = y[i];
        y2[i] = y[i] + c[i];
    }

    DSU dsu(n);

    f0(i, 0, n-1){
        f0(j, i+1, n-1){
            if(touch(i, j))dsu.Uni(i, j);
        }
    }

    unordered_map<int, int64> dt;

    f0(i, 0, n-1){
        int r = dsu.find(i);
        int64 a = d[i] * c[i];

        dt[r] += a;
    }

    int64 ans = 0;
    for(auto &kv:dt)ans = max(ans, kv.se);

    cout<<ans;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


