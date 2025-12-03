#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "tenbai"
const ll maxn = 1e6 + 5;
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
ll d[maxn]; 

void sang(ll r) {
    FOR(i,1,r)
        for (ll j = i; j <= r; j += i)
            d[j] += i;
}


int main() {
    if(fopen(TASK".INP","r")){
        freopen(TASK".INP","r",stdin);
        freopen(TASK".OUT","w",stdout);
    }
    ll l, r;
    cin >> l >> r;
    sang(r);
    ll cnt = 0;
    FOR(i,l,r)cnt+=(d[i]-i>i?1:0);
    cout <<cnt;;
}
