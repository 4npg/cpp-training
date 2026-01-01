// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)
#define base 31

string s;
int q;
vector<unsigned long long> h(maxn+1), p(maxn+1);

int getHash(int l, int r){
    return h[r] - h[l] * p[r-l];
}
con_meo_dua_leo(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    cin>>s;
    int n = s.size();
    h.resize(n+1); p.resize(n+1);
    p[0] = 1;
    f0(i, 0, n-1){
        h[i+1] = h[i] * base + (unsigned long long)(s[i] - '0' + 1);
        p[i+1] = p[i] * base;
    }

    cin>>q;
    while(q--){
        int a, b, l;
        cin>>a>>b>>l;
        a--; b--;
        int len = l+1;

        int lo = 0, hi = len;
        while(lo < hi){
            int mid = (lo + hi + 1)/2;
            if(getHash(a, a+mid) == getHash(b, b+mid))lo = mid;
            else hi = mid -1;
        }

        if(lo == len){
            cout<<"=\n";
        }else{
            if(s[a+lo] > s[b+lo])cout<<">\n";
            else if(s[a+lo] < s[b+lo])cout<<"<\n";
            else cout<<"=\n";
        }
    }
    cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
