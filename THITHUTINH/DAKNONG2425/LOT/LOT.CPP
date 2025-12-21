// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "LOT"

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 200005
#define pb push_back

int n, k;
int64 ans;
int64 a[maxn];

void dfs(int pos, int used, int last, int64 sum){
    ans = max(ans, sum);
    if(used == k)return ;
    if(pos>=n)return ;

    for(int i=pos; i<n; ++i){
        if(last != -1 && a[i] != last+1)continue;

        int64 curs = 0;
        int64 pre = a[i];

        f0(j, i, n-1){
            if(j>i){
                if(a[j] != pre+1)break;
                pre = a[j];
            }
            curs += a[j];
            dfs(j+1, used+1, a[j], sum+curs);
        }
    }
}

youngboiz_nobug(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    //freopen(file".out", "w", stdout);

    cin>>n>>k;
    f0(i, 0, n-1)cin>>a[i];
    ans=0;
    dfs(0, 0, -1, 0);
    cout<<ans;
    cerr<<"\ntime elapsed: "<<TIME<<"s.\n";
}
