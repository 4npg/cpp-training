#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
#define nl cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define fi first
#define se second


const ll maxn = 1e7;
ll a[maxn];
int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n,s;cin>>n>>s;
    unordered_map<ll,ll> freq;
    FOR(i,0,n-1){
        cin>>a[i];
        freq[a[i]]++;
    }
    ll cnt=0;
    for(auto x:freq){
        if(freq.count(s-x.fi)&&freq[s-x.fi]>=1){
            freq[x.fi]=0;
            freq[s-x.fi]=0;
            cout<<x.fi<<" "<<s-x.fi;
            nl;
            cnt++;
        }
    }
    cout<<cnt;
}


