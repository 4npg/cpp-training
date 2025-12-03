// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define all(a) (a).begin(),(a).end()
#define inf (int64)-1
#define maxn 100005

int n, q;
int64 a[maxn];

struct Node{
    int64 ma1, ma2;
};
Node t[maxn*4];

Node mergeNode(Node L, Node R){
    vector<int64> v = {L.ma1, L.ma2, R.ma1, R.ma2};
    sort(all(v), greater<int64>());
    return {v[0], v[1]};
}

void build(int64 id, int64 l, int64 r){
    if(l == r){
        t[id] = {a[l], inf};
        return;
    }

    int64 mid = (l+r)/2;
    build(id*2, l, mid);
    build(id*2+1, mid+1, r);

    t[id] = mergeNode(t[id*2], t[id*2+1]);
}

void update(int64 id, int64 l, int64 r, int64 p, int64 x){
    if(l == r){
        t[id] = {x, inf};
        return;
    }   

    int64 mid = (l+r)/2;
    if(p<=mid)update(id*2, l, mid, p, x);
    else update(id*2+1, mid+1, r, p, x);
    t[id] = mergeNode(t[id*2], t[id*2+1]);
}

Node get(int64 id, int64 l, int64 r, int64 u, int64 v){
    if(v<l || r<u)return {inf, inf};
    if(u<=l && r<=v)return t[id];
    int64 mid = (l+r)/2;
    Node tl = get(id*2, l, mid, u, v);
    Node tr = get(id*2+1, mid+1, r, u, v);
    return mergeNode(tl, tr);
}

int64 mul(int64 a, int64 b, int64 mod){
    int64 ans = 0;
    while(b){
        if(b&1)ans = (ans+a)%mod;
        a = (a+a)%mod;
        b>>=1;
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    cin>>n;
    f0(i, 1, n)cin>>a[i];
    build(1, 1, n);

    cin>>q;
    while(q--){
        int64 type, u, v;
        cin>>type>>u>>v;
        if(type==0)update(1, 1, n, u, v);
        else{
            int64 mod;
            cin>>mod;
            Node res = get(1, 1, n, u, v);
            if(res.ma2<1){
                if(res.ma1<1){
                    cout<<0<<'\n';
                }else cout<<res.ma1%mod<<'\n';
            }else cout<<mul(res.ma1, res.ma2, mod)<<'\n';
        }
    }

    cerr << "time elapsed: "<<TIME <<"s.\n";
} 





