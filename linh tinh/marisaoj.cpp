// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;int64 s;
vector<int64>w;
vector<int64>v;
int64 ans;
void Try(int i,int64 cw,int64 cv){
    if(i==n){
        if(cw<=s)ans = max(ans,cv);
        return;
    }
    Try(i+1,cw,cv);
    if(cw+w[i]<=s){
        Try(i+1,cw+w[i],cv+v[i]);
    }
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>s;
    v.resize(n);w.resize(n);
    f0(i,0,n-1){
        cin>>w[i]>>v[i];
    }
    ans=0;
    Try(0,0,0);
    cout<<ans;
}


