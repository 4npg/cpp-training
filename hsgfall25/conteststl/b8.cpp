// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define f0(i,a,b) for(int (i)=(a);i<=(b);++i)

int n,m,q;
int32_t main() {
    fast;
    cin>>n>>m>>q;
    vector<vector<int64>>a(n,vector<int64>(m));
    vector<int64> srow(n);
    vector<int64> scol(m);
    f0(i,0,n-1){
        f0(j,0,m-1){
            cin>>a[i][j];
            srow[i]+=a[i][j];
            scol[j]+=a[i][j];
        }
    }
    while(q--){
        int i,j;
        int64 k;
        char x;cin>>x;
        if(x=='r'){
            cin>>i;
            cout<<srow[--i];
            el;
        }
        if(x=='c'){
            cin>>i;
            cout<<scol[--i];
            el;
        }
        if(x=='2'){
            cin>>i>>j>>k;
            i--;j--;
            srow[i]-=a[i][j];
            scol[j]-=a[i][j];
            a[i][j] = k;
            srow[i]+=k;
            scol[j]+=k;
        }
        if(x=='1'){
            cin>>i>>j;
            i--;j--;
            swap(a[i],a[j]);
            swap(srow[i],srow[j]);
        }
    }
    for(auto &x:a){
        for(auto &v:x){
            cout<<v<<" ";
        }
        el;
    }
}


