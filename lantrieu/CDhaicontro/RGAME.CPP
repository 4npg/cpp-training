// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n,k,s;

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","w",stdin);
    freopen(file".out","w",stdout);
    cin>>n>>s>>k;

    vector<int> L(n+1), R(n+1);

    f0(i,1,n){
        L[i] = i-1;
        R[i] = i+1;
    }

    L[1] = n;
    R[n] = 1;

    int m = n, p = 1;
    while(m>1){
        f0(i,1,s-1)p = R[p];
        R[L[p]] = R[p];
        L[R[p]] = L[p];

        m--;
        p = R[p];
    }

    cout<<p<<'\n';

    int kq = 1+k-p;
    if(k<p)kq+=n;
    cout<<kq;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


