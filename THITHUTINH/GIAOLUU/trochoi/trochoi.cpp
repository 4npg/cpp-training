// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "trochoi"

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long Rand(long long l, long long r){
    return l+rng()%(r-l+1);
}

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int q;

long long cnt(long long x){
    long long dem = 0;
    for(int i = 1; i*i<=x; i++){
        if(x%i == 0){
            dem+=i;
            if(x/i!=i)dem+=x/i;
        }
    }
    return dem;
}

void sub1(){
    while(q--){
        long long x; cin>>x;
        cout<<cnt(x)<<" ";
    }
}

int d[maxn];

void sang(){
    for(int i=2; i<maxn; i++){
        for(int j=i; j<maxn; j+=i)d[j]+=i;
    }
}

long long mul(long long a, long long b, long long m){
    long long ans = 0;
    while(b){
        if(b&1) ans = (ans + a) % m;
        a = (a + a) % m;
        b >>= 1;
    }
    return ans;
}

long long opw(long long a, long long b, long long m){
    long long ans = 1;
    while(b){
        if(b&1) ans = mul(ans, a, m);
        a = mul(a, a, m);
        b >>= 1;
    }
    return ans;
}


bool check(long long a, long long s, long long n){
    long long x = opw(a, s, n);
    if(x == 1 || x==n-1)return 1;
    while(s<n-1){
        x = mul(x, x, n);
        if(x == n-1)return 1;
        s *= 2;
    }
    return 0;
}

bool miller(long long n){
    if(n<2)return 0;
    vector<int> a = {2, 3, 5, 7, 11, 13, 17, 19, 23};

    long long s = n-1;
    while(s%2==0)s /= 2;

    for(auto &p:a){
        if(n == p)return 1;
        if(!check(p, s, n))return 0;
    }
    return 1;
}

long long gcd(long long a, long long b){
    if(b == 0)return a;
    return gcd(b, a%b);
}

long long rho(long long n){
    if(n%2 == 0)return 2;
    long long x = Rand(2, n-1);
    long long y = x;
    long long c = Rand(1, n-1);
    long long g = 1;

    while(g == 1){
        x = (mul(x, x, n) + c)%n;
        y = (mul(y, y, n) + c)%n;
        y = (mul(y, y, n) + c)%n;

        g = gcd(abs(x-y), n);
    }
    if(g == n)return rho(n);
    return g;
}

vector<long long> facs;

void phantich(long long n){
    if(n == 1)return;

    if(miller(n)){
        facs.emplace_back(n);
        return;
    }

    long long p = rho(n);
    phantich(p);
    phantich(n/p);
}

void sub4(){
    while(q--){
        long long x; cin>>x;
        if(x < maxn){
            cout<<d[x] + 1<<" ";
        }else {
            facs.clear();
            phantich(x);
            sort(facs.begin(), facs.end());
            long long sum = 1;
            for(auto &p:facs)sum += p;
            cout<<sum<<" ";
        }
    }
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);
    sang();
    cin>>q;

    //sub4();
    while(q--){
        long long x; cin>>x; cout<<d[x]+1<<" ";
    }

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
