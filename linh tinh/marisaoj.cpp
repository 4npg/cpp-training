// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 100005

int n,d;
int64 a[maxn];
int64 pre[maxn];
int64 ans;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>d;
    pre[0] = 0;
    f0(i, 1, n){
        cin>>a[i];
        pre[i] = pre[i-1] + a[i];
    }

    map<int64, int> mp;

    f0(r, 1, n){
        mp[(pre[r-1]%d+d)%d]++;
        ans += mp[(pre[r]%d+d)%d];
    }

    cout<<ans;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}





