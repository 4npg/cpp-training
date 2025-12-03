/*
    www.youtube.com/YugiHackerChannel
    linktr.ee/YugiHacker
*/
#include<bits/stdc++.h>
#define el cout<<"\n"
#define f0(i,n) for(int i=0;i<n;++i)
#define f1(i,n) for(int i=1;i<=n;++i)
#define maxn 1000006
#define base 34
#define MOD 1000000007
using namespace std;
string s, t;
int n, m;
long long h[maxn], p[maxn];
long long get_hash(int l, int r) {
    //return ((h[r] - h[l-1] * p[r-l+1]) % MOD + MOD) % MOD;
    //return (h[r] - h[l-1] * p[r-l+1] + 1ll * MOD * MOD) % MOD;
    return (h[r] - h[l-1] * p[r-l+1] % MOD + MOD) % MOD;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> s >> t;
    n = s.size();
    m = t.size();
    s = ' ' + s;
    p[0] = 1;
    for (int i=1; i<=n; i++) {
        h[i] = (h[i-1] * base + s[i] - 'a' + 1) % MOD;
        p[i] = p[i-1] * base % MOD;
    }
    long long hashT = 0;
    for (int i=0; i<t.size(); i++) hashT = (hashT * base + t[i] - 'a' + 1) % MOD;
    int ans = 0;
    for (int i=1; i+m-1 <= n; i++) {
        if (get_hash(i, i+m-1) == hashT)
            ans++;
    }
    cout << ans;
}