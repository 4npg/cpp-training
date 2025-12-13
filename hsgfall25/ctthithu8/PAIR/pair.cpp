// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define file "pair"
#define int64 long long
#define f0(i, a, b) for(int (i) = (a); (i) <= (b); ++i)
#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define maxn 1000006
#define se second

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

void sub1(){
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
}

int d[maxn];

void sang(){
    d[1] = 1;
    for (int i = 2; i <= maxn; i++) {
        if (!d[i]) {
            d[i] = i;
            if ((int64)i * i <= maxn)
                for (int j = i * i; j <= maxn; j += i)
                    if (!d[j]) d[j] = i;
        }
    }
}

unordered_map<int, int> freq;

int dm(int x){
    int res = 1;
    while(x > 1){
        int p = d[x];
        int c = 0;
        while(x % p == 0){
            x /= p;
            c ^= 1;
        }
        if (c) res *= p;
    }
    return res;
}


void sub2(int n){
    sang();
    freq.reserve(n*2);
    f0(i, 1, n){
        int x; cin>>x;
        freq[dm(x)]++;
    }

    int64 ans = 0;
    for(auto &kv:freq){
        int64 c = kv.se;
        ans += c*(c-1)/2;
    }

    cout<<ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n;
    if(n<=1000)sub1();
    else sub2(n);

    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
