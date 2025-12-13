// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "pair"
#define int64 long long
#define f0(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 1000006

int n;
int a[maxn];
int cnt;

bool cp(int64 x) {
    int64 r = sqrtl(x);
    return r*r == x;
}

int64 gcd(int64 a, int64 b) {
    while(b) {
        int64 t = a % b;
        a = b;
        b = t;
    }
    return a;
}

int64 lcm(int64 a, int64 b) {
    return a / gcd(a, b) * b;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".ans","w",stdout);

    cin>>n;
    f0(i, 1, n)cin>>a[i];

     int64 cnt = 0;

    f0(i,1,n){
        f0(j,i+1,n){
            if(cp(lcm(a[i], a[j])/gcd(a[i], a[j]))){
                cnt++;
            }
        }
    }

    cout << cnt;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
