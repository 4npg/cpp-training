// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file ""
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen(file".inp","w",stdin);
    //freopen(file".out","w",stdout);

    int n,m;
    cin>>n>>m;
    vector<int> L(n+2), R(n+2);
    for(int i = 1; i<=n; i++){
        L[i] = i - 1;
        R[i] = i + 1;
    }

    R[0] = 1;
    L[n+1] = n;
    for(int k=1;k<=m;k++){
        int i,j;
        cin>>i>>j;
        // xoa i ra khoi day
        R[L[i]] = R[i];
        L[R[i]] = L[i];

        // chen i vao ben trai j
        R[L[j]] = i;
        L[i] = L[j];
        L[j] = i;
        R[i] = j;
    }

    for(int i = 1; i<=n ;i++){
        cout<<L[i]<<" ";
        if(R[i] == n+1) cout<<0;
        else cout<<R[i];
        cout<<'\n';
    }

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
