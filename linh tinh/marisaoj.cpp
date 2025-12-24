// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file ""

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define mod (int64)(1e9+7)
#define pb push_back

int n;
int a[maxn];
int d[maxn];
vector<int> nto;

void sang(){
    for(int i=2; i*i<maxn; i++){
        if(d[i] == 0){
            for(int j=i; j<maxn; j+=i){
                if(d[j] == 0)d[j] = i;
            }
        }
    }

    f0(i, 2, maxn-1)if(!d[i])nto.pb(i);
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    sang();

    cin>>n;

    f0(i, 0, n-1){
        int x; cin>>x;
        int mu = 0;
        for(auto &p:nto){
            if(x%p==0){
                int cnt = 0;
                while(x%p==0){
                    x/=p;
                    cnt++;
                }
                cout<<p<<" "<<cnt<<'\n';
            }
        }
        cout<<'\n';
    }

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
