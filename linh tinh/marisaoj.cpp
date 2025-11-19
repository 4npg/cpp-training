// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005


int n;
int64 a[maxn], x;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>x;

    f0(i,0,n-1){
        cin>>a[i];
    }

    int ans = 0;
    int lo = 0, hi = n-1;

    while(lo < hi){
        if(a[lo] + a[hi] == x){
            ans++;
            lo++;
            hi--;
        }else if(a[lo] + a[hi] < x) lo++;
        else hi--;
    }
    cout<<ans;
    cerr << "time elapsed: "<<TIME <<"s.\n";
}


