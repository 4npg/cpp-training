// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,m;
int64 k;
const int maxn = 1e6+5;
int64 a[maxn];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>m>>n>>k;
    vector <int64> pre(m+1,0);
    pre[0] = 0;
    f0(i,1,m){
        cin>>a[i];
    }
    sort(a+1,a+m+1);
    f0(i,1,m)pre[i] = pre[i-1] + a[i];
    int64 ans = -2;
    f0(i,1,m){
        if(i-n+1>=1&&a[i]-a[i-n+1]<=k)ans = max(ans,pre[i]-pre[i-n]);
    }
    cout<<ans;
}


