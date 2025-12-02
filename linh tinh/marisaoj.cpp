// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 100005

int n,d;
int64 a[maxn];
int64 pre[maxn];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>n>>d;
    pre[0] = 0;
    f0(i, 0, n-1){
        cin>>a[i];
        pre[i+1] = pre[i] + a[i];
    }

    f0(i,0,n-1){
        f0(j, i+1, n-1){
            cerr<<i<<" "<<j<<" "<<pre[j] - pre[i-1]<<'\n';
        }
    }

    cerr << "time elapsed: "<<TIME <<"s.\n";
}





