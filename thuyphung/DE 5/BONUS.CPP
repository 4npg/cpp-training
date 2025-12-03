#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
const ll maxn = 1e7;
ll a[maxn];
void READFILE(){
    freopen("BONUS.INP","r",stdin);
    freopen("BONUS.OUT","w",stdout);
}
int main() {
    fast;READFILE();
    ll n;cin>>n;
    for (ll i=0;i<n;++i)cin>>a[i];
    ll res = 0;
    for (ll i = 0; i < n; ++i) {
        ll maxe = a[i], mine = a[i];
        for (ll j = i; j < n;j++) {
            maxe = max(maxe, a[j]);
            mine = min(mine, a[j]);
            res += (maxe - mine);
        }
    }

    cout << res;
}
