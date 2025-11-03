// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define int long long
#define f0(i,a,b) for(int i=(a);i<=(b);i++)
#define file "bai4"
#define maxn 100005

int n,m;

int parent[maxn];

int find(int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent[x]);
}

void unite(int x,int y){
    x=find(x);
    y=find(y);
    if(x!=y) parent[x]=y;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    //freopen(file".out","w",stdout);

    cin>>n>>m;

    if(m==0){
        cout<<n;
        return 0;
    }

    f0(i,1,n) parent[i]=i;

    f0(i,1,m){
        int u,v;
        cin>>u>>v;
        unite(u,v);
    }

    int components=0;
    f0(i,1,n){
        if(parent[i]==i) components++;
    }

    int ans;
    if(components==1){
        ans = n-1;
    } else {
        ans = n - (components-1);
    }

    cout<<ans;
}
