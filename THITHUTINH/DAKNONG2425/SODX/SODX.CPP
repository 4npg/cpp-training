// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "SODX"

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006

bool d[maxn];
int64 l, r;

void sang(){
    d[0] = d[1] = 1;

    for(int i=2; i*i<maxn; ++i){
        if(d[i] == 0){
            for(int j=i*i; j<maxn; j+=i){
                d[j] = 1;
            }
        }
    }
}

int tcs(int64 x){
    int res = 0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}

int64 makepalin(int64 x, bool odd){
    int64 p = x;
    if(odd)x/=10;
    while(x){
        p = p*10 + (x%10);
        x/=10;
    }
    return p;
}

youngboiz_nobug(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
//    freopen(file".out", "w", stdout);

    sang();

    cin>>l>>r;

    int64 ans = 0;
    f0(len, 1, 12){
        int hlen = (len+1)/2;

        int64 st = 1;
        f0(i, 1, hlen-1)st *= 10;
        int64 ed = st * 10 - 1;

        bool odd = (len&1);

        for(int64 x = st; x<=ed; ++x){
            int64 p = makepalin(x, odd);
            if(p<l)continue;
            if(p>r)break;

            if(!d[tcs(p)])++ans;
        }
    }

    cout<<ans;

    cerr<<"\ntime elapsed: "<<TIME<<"s.\n";
}
