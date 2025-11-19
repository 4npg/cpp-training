// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "DAYSO"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 100005

int n;
int64 a[maxn];
int64 k;
int64 ans;
int cnt;
bool ok = false;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);
    cin>>k>>n;
    f0(i,0,n-1){
        cin>>a[i];
        if(a[i]>k){
            ok = true;
            cnt++;
            ans += a[i];
        }
    }
    if(ok){
        cout<<ans<<'\n'<<cnt<<'\n'<<"TRUE";
    }else{
        cout<<"FALSE";
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
