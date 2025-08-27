// author : anphung
// github : 4npg
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,q;
const int maxn = 1e5+5;


int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>q;
    vector<int64> pre(n);
    pre[0] = 0;
    f0(i,1,n){
        int64 x;
        cin>>x;
        pre[i] = pre[i-1] + x;
    }
    int64 mx = -1e9;
    int lo = 1;
    int hi = n;
    while(lo<=hi){
        mx = max(mx,pre[hi]-pre[lo-1]);
        lo++;
    }
}


