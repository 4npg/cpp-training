// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//    return l+rng()%(r-l+1);
//}

#define maxn 
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int t;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>t;
    while(t--){
        int n, p, q; cin>>n>>p>>q;
        vector<long long> a(n+1, 0);

        f0(i, 1, n)cin>>a[i];
        int k = p + q;
        if(k == 0){
            long long mx = a[1], mn = a[1];
            f0(i,1,n){
                mx = max(mx, a[i]);
                mn = min(mn, a[i]);
            }
            cout << mx - mn << '\n';
            continue;
        }

        vector<long long> v;
        f0(i, 1, n)v.emplace_back(abs(a[i]));

        sort(v.begin(), v.end(), greater<long long>());

        int m = min(n, k+2);

        long long ans = 0;
        f0(i, 0, m-1){
            ans += v[i];
        }

        cout<<ans<<'\n';
    }
    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
