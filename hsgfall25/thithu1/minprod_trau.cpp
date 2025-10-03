#include<bits/stdc++.h>
using namespace std;
#define file "minprod"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn (int)1e5+10
#define fi first
#define se second

int n;
int64 a[maxn],b[maxn];


void sub1(){
    int64 ans = -1e6;
    f0(i,0,n-1){
        f0(j,0,n-1){
            if(i!=j){
                ans = max(ans,min(a[i]*a[j]*1ll,b[i]*b[j]*1ll));
            }
        }
    }
    cout<<ans;
}


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);
    cin>>n;
    f0(i,0,n-1)cin>>a[i];
    f0(i,0,n-1)cin>>b[i];
    /*
    if(n<=3000)sub1();
    else sub2();
    */
    sub1();
    cerr <<'\n'<< "time elapsed: "<<TIME <<"s.\n";
}
