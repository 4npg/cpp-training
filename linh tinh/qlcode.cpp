// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "doancon"

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 200005

int n, k;
int64 m;
int b[maxn];

int64 opw(int64 a, int64 b, int mod){
    int64 ans = 1;
    while(b){
        if(b&1)ans = (ans*a)%mod;
        a = (a*a)%mod;
        b>>=1;
    }
    return ans;
}

con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    cin>>n>>m>>k;

    f0(i, 1, n){
        string s; cin>>s;
        int64 amod = 0;
        for(auto c:s){
            amod = (amod*10+(c-48))%k;
        }
        b[i] = opw(amod, m, k);
    }

    unordered_map<int, int>freq;

    freq[0] = 1;

    int64 ans = 0;
    int cur = 0;
    f0(i, 1, n){
        cur = (cur+b[i])%k;
        ans += freq[cur];
        freq[cur]++;
    }

    cout<<ans;

    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
