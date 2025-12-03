#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "TERACING"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(a,b) for(ll i=(a);i<=(b);++i)
#define fi first
#define se second

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n,k;cin>>n>>k;
    unordered_map<ll,ll> freq;
    FOR(0,n-1){
        ll x;cin>>x;
        freq[x]++;
    }
    ll res = 0;
    for(auto &x:freq){
        if(freq.count(x.fi+k)){
            res+=1ll*x.se*freq[x.fi+k];
        }
    }
    cout<<res;
}


