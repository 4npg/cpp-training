// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "task"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 100005

int n;
int64 a[maxn];
int64 pre[maxn];
int cnt;

youngboiz_nobug(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>n;

    f0(i, 1, n){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }


    f0(l, 1, n){
        f0(r, l, n){
            if(pre[r] - pre[l-1] == 0)cnt++;
        }
    }

    cout<<cnt;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
