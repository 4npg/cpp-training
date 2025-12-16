// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define u64 unsigned long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "MAGIC"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 200005

int n, q;

int64 a[maxn];
int64 b[maxn];
u64 prea[maxn], preb[maxn];
unordered_map<int64, u64> h;


int64 gethash(int64 x){
    if(!h.count(x))h[x] = rng();
    return h[x];
}

void sub1(){
    while(q--){
        int x, y;
        cin>>x>>y;
        set<int> aset;
        set<int> bset;
        f0(i, 0, x-1)aset.insert(a[i]);
        f0(i, 0, y-1)bset.insert(b[i]);

        if(aset == bset){
            cout<<"Yes\n";
        }else cout<<"No\n";
    }
}

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    //freopen(file".out", "w", stdout);

    cin>>n;
    f0(i, 0, n-1)cin>>a[i];
    f0(i, 0, n-1)cin>>b[i];

    cin>>q;

    prea[0] = 0;
    unordered_set<int64> seenA;
    f0(i,0,n-1){
        prea[i+1] = prea[i];
        if(!seenA.count(a[i])){
            seenA.insert(a[i]);
            prea[i+1] ^= gethash(a[i]);
        }
    }


    preb[0] = 0;
    unordered_set<int64> seenB;
    f0(i,0,n-1){
        preb[i+1] = preb[i];
        if(!seenB.count(b[i])){
            seenB.insert(b[i]);
            preb[i+1] ^= gethash(b[i]);
        }
    }


    while(q--){
        int x, y; cin>>x>>y;
        if(prea[x] == preb[y])cout<<"Yes\n";
        else cout<<"No\n";
    }

    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
