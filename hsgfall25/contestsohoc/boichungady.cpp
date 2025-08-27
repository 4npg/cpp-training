// author : anphung 
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define pb push_back
#define fi first 
#define se second
const int MOD = 1e9+7;
const int maxn = 100000+5;

int d[maxn];
vector<int> nto;
int ntoi[maxn];       
int mxexp[maxn];         


int64 ipow(int64 a, int64 b){
    int64 ans = 1;
    while(b){
        if(b&1) ans = ans * a % MOD;
        a = a * a % MOD;
        b >>= 1;
    }
    return ans;
}

void sang(){
    d[0] = d[1] = 1;
    for(int i=2;i*i<maxn;++i){
        if(!d[i]){
            for(int j=i*i;j<maxn;j+=i) d[j] = 1;
        }
    }
    for(int i=2;i<maxn;++i){
        if(!d[i]){
            ntoi[i] = nto.size();
            nto.pb(i);
        }
    }
}

vector<pair<int,int>> ptich(int x){
    vector<pair<int,int>> res;
    for(int p: nto){
        if(1LL*p*p > x) break;
        if(x%p==0){
            int cnt=0;
            while(x%p==0){ x/=p; ++cnt; }
            res.pb({ntoi[p], cnt});
        }
    }
    if(x>1) res.pb({ntoi[x], 1});
    return res;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    sang();

    int n, q;
    cin>>n>>q;
    vector<unordered_map<int,int>> expo(n);  

    vector<int> a(n);
    for(int i=0;i<n;++i) cin >> a[i];

    int64 L = 1;

    for(int i=0;i<n;++i){
        auto f = ptich(a[i]);
        for(auto &pe : f){
            int id = pe.fi, e = pe.se;
            expo[i][id] = e;
            if(e > mxexp[id]){
                L = L * ipow(nto[id], e - mxexp[id]) % MOD;
                mxexp[id] = e;
            }
        }
    }

    while(q--){
        int idx, x;
        cin >> idx >> x;
        --idx;
        auto f = ptich(x);
        for(auto &pe : f){
            int id = pe.fi, e = pe.se;
            int ne = expo[idx][id] + e;
            expo[idx][id] = ne;
            if(ne > mxexp[id]){
                L = L * ipow(nto[id], ne - mxexp[id]) % MOD;
                mxexp[id] = ne;
            }
        }
        cout << L << '\n';
    }
}
