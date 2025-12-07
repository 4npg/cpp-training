// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "task"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 10004

int n;
int64 a[maxn];
int64 cnt = 0;

bool pwo2(int n){
    return (n&(n-1))==0;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>n;
    f0(i, 0, n-1)cin>>a[i];

    f0(i, 0, n-1){
        f0(j, i+1, n-1){
            if(pwo2(a[i]+a[j])){
                cnt++;
            }
        }
    }

    cout<<cnt;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
