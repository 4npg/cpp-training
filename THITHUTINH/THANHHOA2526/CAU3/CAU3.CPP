// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define file "CAU3"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

#define maxn 1000006
#define fi first
#define se second

int n, m;
int cnt;
int a[maxn], b[maxn];
bool bad[maxn];

int gcd(int a, int b){
    if(b == 0)return a;
    return gcd(b, a%b);
}

void sub1(){
    f0(i, 0, n-1){
        bool ok = true;
        f0(j, 0, m-1){
            if(gcd(a[i], b[j]) != 1){
                ok = false;
            }
        }
        cnt += (ok);
    }

    cout<<cnt;
}

int d[maxn];

void sang(){
    for(int i=2; i<maxn; ++i){
        if(d[i] == 0){
            for(int j=i; j<maxn; j+=i)
                if(d[j] == 0)d[j] = i;
        }
    }
}

void sub2(){
    f0(i, 0, m-1){
        int x = b[i];
        while(x>1){
            int p = d[x];
            bad[p] = 1;
            while(x%p==0)x/=p;
        }
    }

    f0(i, 0, n-1){
        int x = a[i];
        bool ok = true;
        while(x>1){
            int p = d[x];
            if(bad[p]){
                ok = false;
                break;
            }
            while(x%p==0)x/=p;
        }
        cnt+=ok;
    }

    cout<<cnt;
}

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);


    sang();

    cin>>n>>m;
    f0(i, 0, n-1)cin>>a[i];
    f0(j, 0, m-1)cin>>b[j];

    sub2();

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
