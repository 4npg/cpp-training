// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i=(a); i<=(b);++i)
#define fd(i,a,b) for(int i=(a); i>=(b);--i)
#define file "hopqua"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 200005
#define inf 4e18

int n, m;
int64 a[maxn], b[maxn];
int64 sum;

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
//    freopen(file".out","w",stdout);

    cin>>n>>m;
    f0(i, 0, n-1)cin>>a[i];
    f0(i, 0, m-1)cin>>b[i];

    sort(a, a+n);
    sort(b, b+m);

    int i = 0, j = 0;

    while(j<m){
        while(i<n && a[i] < b[j])i++;

        if(i == n){
            cout<<-1;
            return 0;
        }

        sum += a[i];
        i++;
        j++;
    }

    cout<<sum;
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
