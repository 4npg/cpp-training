#include<bits/stdc++.h>
using namespace std;
#define file "prime"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn (int)1e6+10

int n;
int a[maxn];
bitset<maxn>d;

void sub1(){
    int ans = -1e6;
    int prev_cnt = 0;
    f0(i,0,n-1){
        int cnt = 0;
        int nn = a[i];
        for(int j=2;j*j<=nn;j++){
            if(nn%j==0){
                while(nn%j==0){
                    nn/=j;
                }
                cnt++;
            }
        }
        if(nn>1)cnt++;
        if(prev_cnt<cnt){
            prev_cnt = cnt;
            ans = a[i];
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
    sub1();
    cerr <<'\n'<< "time elapsed: "<<TIME <<"s.\n";
}
