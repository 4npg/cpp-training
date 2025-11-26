// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 100005

int n;
int64 a[maxn], k;

int64 check(int64 mid){
    int64 len = 1, x = a[0];

    f0(i,0,n-1){
        if(a[i]-x>=mid){
            len++;
            x = a[i];
        }
    }
    return len;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>k;
    f0(i,0,n-1)cin>>a[i];

    sort(a,a+n);
    int cnt=0;
    int64 lo = 0, hi = 1e9;
    int64 ans = -1;
    while(lo <= hi){
        int64 mid = lo + ((hi-lo)>>1);
        if(check(mid)>=k){
            lo = mid + 1;
        }else hi = mid - 1;
        cnt++;
        cerr<<cnt<<" "<<mid<<" "<<check(mid)<<'\n';
    }        
    cout<<hi;
    cerr<<'\n'<<cnt;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}





