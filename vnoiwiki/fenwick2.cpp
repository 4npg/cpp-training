// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//  return l+rng()%(r-l+1);
//}

#define maxn 100005
#define pb push_back
#define fi first 
#define se second 

int n, q;
vector<int64> bit1(maxn), bit2(maxn);

void updatediem(vector<int64> &b, int u, int64 v){
    int i = u;
    while(i <= n){
        b[i] += v;
        i += (i&(-i));
    }
}

void updatedoan(int l, int r, int64 v){
    updatediem(bit1, l, v);
    updatediem(bit1, r+1, -v);

    updatediem(bit2, l, v*(l-1));
    updatediem(bit2, r+1, -v*r);
}

int64 get(int u){
    int i = u;
    int64 ans = 0;
    while(i){
        ans += bit1[i]*u - bit2[i];
        i -= (i&(-i));
    }
    return ans;
}

int64 getpre(int l, int r){
    return get(r) - get(l-1);
}

youngboiz_nobug(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>q;
    f0(i, 1, n){
        int64 x; cin>>x;
        updatedoan(i, i, x);
    }

    while(q--){
        int type; cin>>type;
        if(type == 1){
            int u, v;
            int64 x;
            cin>>u>>v>>x;
            updatedoan(u, v, x);
        }else{
            int u, v; cin>>u>>v;
            cout<<getpre(u, v)<<'\n';
        }
    }
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
