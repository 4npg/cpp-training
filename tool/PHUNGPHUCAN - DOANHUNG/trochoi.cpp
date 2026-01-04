// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "trochoi"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n;
long long sum[maxn];
long long cnt[maxn];
bool d[maxn];
vector<int> nto;
long long ans = 0;
long long a[maxn];

void sang(){
    for(int i=2; i*i<maxn; i++){
        if(!d[i]){
            for(int j=i*i; j<maxn; j+=i){
                d[j] = 1;
            }
        }
    }

    f0(i, 2, maxn-1){
        if(!d[i])nto.emplace_back(i);
    }
}

void sangdoan(long long l, long long r){

    f0(i, 0, r-l){
        cnt[i] = l+i;
        sum[i] = 1;
    }

    for(int p:nto){
        if(1LL*p*p>r)break;
        long long st = max(1LL*p*p, ((l+p-1)/p)*p);

        for(long long x = st; x<=r; x+=p){
            if(cnt[x-l]%p != 0)continue;

            long long pw = 1;
            long long cur = 1;

            while(cnt[x-l]%p == 0){
                cnt[x-l] /=p;
                pw *= p;
                cur += pw;
            }
            sum[x-l] *= cur;
        }
    }

    f0(i, 0, r-l){
        if(cnt[i] > 1){
            sum[i] *= (1 + cnt[i]);
        }
    }
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    freopen(file".out", "w", stdout);

    sang();
    cin>>n;

    long long mi = inf;
    long long ma = -inf;
    f0(i, 0, n-1){
        cin>>a[i];
        ma = max(ma, a[i]);
        mi = min(mi, a[i]);
    }
    sangdoan(mi, ma);

    f0(i, 0, n-1){
        cout<<sum[a[i] - mi]<<" ";
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
