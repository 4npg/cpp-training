// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, k;
int a[maxn];

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);

    cin>>n>>k;
    f0(i, 0, n-1)cin>>a[i];

    int m = n/k;

    vector<vector<int>> gr(k);

    f0(i, 0, n-1)gr[i%k].emplace_back(a[i]);

    f0(i, 0, k-1)sort(gr[i].begin(), gr[i].end());


    vector<int> res(n);
    f0(i, 0, m-1){
        f0(j, 0, k-1){
            res[i*k+j] = gr[j][i];
        }
    }

    long long ans = 0;
    f0(i, 0, n-k-1){
        ans += abs(res[i] - res[i+k]);
    }

    cout<<ans;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
