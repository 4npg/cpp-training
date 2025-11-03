// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "PRIME"
#define int64 long long
#define f0(i,a,b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn (int)1e6+10
#define pb push_back

int n;
int a[maxn];
int d[maxn];

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

void sang(){
    d[0] = d[1] = 1;
    for(int i=2;i*i<maxn;i++){
        if(d[i]==0){
            for(int j=i*i;j<maxn;j+=i)
                if(d[j]==0)d[j] = i;
        }
    }
}

void sub2(){
    int ans = -1e6;
    int prev_cnt = 0;
    f0(i,0,n-1){
        int cnt = 0;
        int nn = a[i];
        while(nn>1){
            int p = d[nn];
            if(p==0)p = nn;
            cnt++;
            while(nn%p==0)nn/=p;
        }
        if(prev_cnt<cnt){
            prev_cnt = cnt;
            ans = a[i];
        }
    }
    cout<<ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".INP","r",stdin);
    freopen(file".OUT","w",stdout);
    sang();
    cin>>n;
    f0(i,0,n-1)cin>>a[i];
    if(n<=(int)1e2)sub1();
    else sub2();
    cerr <<'\n'<< "time elapsed: "<<TIME <<"s.\n";
}
