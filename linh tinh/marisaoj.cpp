// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006

int q;

bool d[maxn];
vector<int> nto;
int64 pre[maxn];

void sang(){
    d[0] = d[1] = 1;
    for(int i=2; i*i<maxn; ++i){
        if(d[i] == 0){
            for(int j=i*i; j<maxn; j+=i)d[j] = 1;
        }
    }
}

void sangdoan(int l, int r){
    for(int i=2; i<=maxn; i++){
        int st = (l+i-1)/i*i;
        for(int j=0; st+j<=r; j+=i)if(st+j!=i)d[st+j-l] = 1;
    }
    for(int i=0; i<=r-l; ++i){
        if(!d[i] && i+l>1)nto.pb(i+l);
    }
}



int cnt(int x){
    int dem = 1;
    for(auto &p:nto){
        if(1ll*p*p>x)break;
        if(x%p==0){
            int c = 0;
            while(x%p==0){
                x/=p;
                c++;
            }
            dem *= (c+1);
        }
    }
    if(x>1)dem*=2;
    return dem;

}
i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    sangdoan(1, 1000000);

    pre[0] = 0;
    f0(i, 1, maxn){
        pre[i] = pre[i-1] + cnt(i);
    }

    cin>>q;
    while(q--){
        int l, r;
        cin>>l>>r;
        cout<<pre[r] - pre[l-1]<<'\n';
    }

    cerr << "time elapsed: "<<TIME <<"s.\n";
}




