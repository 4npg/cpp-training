// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

const int base = 34;
const int mod = 1000000007;
const int maxn = 1000006;

string s,t;
int n,m;
int64 hs[maxn];
int64 pw[maxn];

int64 getHash(int l,int r){
    return (hs[r]-hs[l-1]*pw[r-l+1]%mod+mod)%mod;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    cin>>s>>t;
    n = s.size();
    m = t.size();
    s = ' ' + s;    

    pw[0] = 1;
    f0(i,1,n){
        hs[i] = (hs[i-1]*base+s[i]-'a'+1)%mod;
        pw[i] = (pw[i-1]*base)%mod;
    }

    int64 ht = 0;
    f0(i,0,(int)t.size()-1){
        ht = (ht*base + t[i]-'a'+1)%mod;
    }

    int ans = 0;
    for(int i = 1; i+m-1<=n;i++){
        if(getHash(i,i+m-1)==ht) ans++;
    }
    cout << ans;

    cerr << "time elapsed: "<<TIME <<"s.\n";
}


