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
#define mod (long long)(1e9+7)

struct seg{
    int n;
    int t[maxn*4];

    void update(int id, int l, int r, int pos){
        if(l == r){
            t[id]++;
            return;
        }

        int mid = (l+r)/2;
        if(pos<=mid)update(id*2, l, mid, pos);
        else update(id*2+1, mid+1, r, pos);

        t[id] = t[id*2] + t[id*2+1];
    }

    int get(int id, int l, int r, int u, int v){
        if(v<l || r<u)return 0;
        if(u<=l && r<=v)return t[id];

        int mid = (l+r)/2;

        int tl = get(id*2, l, mid, u, v);
        int tr = get(id*2+1, mid+1, r, u, v);

        return tl + tr;
    }
} st;

int n;
long long a[maxn], pre[maxn];

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n;
    f0(i, 1, n){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }
    vector<long long> nen;
    f0(i, 0, n)nen.emplace_back(pre[i]);

    sort(nen.begin(), nen.end());
    nen.erase(unique(nen.begin(), nen.end()), nen.end());

    int m = nen.size();
    long long ans = 0;

    st.update(1, 1, m, lower_bound(nen.begin(), nen.end(), pre[0]) - nen.begin() + 1);

    f0(i, 1, n){
        int pos = lower_bound(nen.begin(), nen.end(), pre[i]) - nen.begin() + 1;
        ans += st.get(1, 1, m, 1, pos);
        st.update(1, 1, m, pos);
    }

    cout<<ans;
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
