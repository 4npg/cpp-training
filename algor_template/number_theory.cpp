#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int64 modpow(int64 a,int64 e,int64 mod){
    int64 r=1;
    a%=mod;
    while(e){
        if(e&1) r = (__int128)r*a%mod;
        a = (__int128)a*a%mod;
        e >>= 1;
    }
    return r;
}

int64 extgcd(int64 a,int64 b,int64 &x,int64 &y){
    if(b==0){ x=1; y=0; return a; }
    int64 x1,y1;
    int64 g = extgcd(b, a%b, x1, y1);
    x = y1; y = x1 - (a/b)*y1;
    return g;
}

int64 modinv(int64 a,int64 mod){
    int64 x,y;
    int64 g = extgcd(a,mod,x,y);
    if(g!=1) return -1;
    x%=mod; if(x<0) x+=mod;
    return x;
}

// Chinese Remainder Theorem (pairwise coprime moduli) - returns (r, M) with x = r (mod M)
pair<int64,int64> crt_pair(int64 a1,int64 m1,int64 a2,int64 m2){
    int64 x,y;
    int64 g = extgcd(m1,m2,x,y);
    if((a2 - a1) % g != 0) return {0,-1}; // no solution
    int64 l = m1 / g * m2;
    int64 t = ((a2 - a1) / g) % (m2/g);
    x = (x % (m2/g) + (m2/g)) % (m2/g);
    t = (__int128)t * x % (m2/g);
    int64 r = (a1 + (__int128)m1 * t) % l;
    if(r<0) r+=l;
    return {r,l};
}

/* linear sieve */
void linear_sieve(int n, vector<int> &pr, vector<int> &lp){
    pr.clear(); lp.assign(n+1,0);
    for(int i=2;i<=n;i++){
        if(lp[i]==0){ lp[i]=i; pr.push_back(i); }
        for(int p: pr){
            if(p>lp[i] || i*p>n) break;
            lp[i*p]=p;
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }
