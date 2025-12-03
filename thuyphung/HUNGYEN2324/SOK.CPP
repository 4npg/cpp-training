#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define TASK "SOK"
#define endl "\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(ll (i)=(a);i<=(b);++i)
#define LOCAL
#define all(a) (a).begin(),(a).end()
#ifdef LOCAL
  #define dbg(x) do { cerr << "[" << #x << "] = " << (x) << '\n'; } while(0)
#else
  #define dbg(x) do {} while(0)
#endif


ll xuli(const vector<ll>& a, ll x) {
    ll cnt = upper_bound(all(a), x) - a.begin();
    return x - cnt;
}


int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    ll n,q;cin>>n>>q;
    vector<ll> a(n);
    FOR(i,0,n-1)cin>>a[i];
    sort(all(a));

    while(q--){
    	ll k;cin>>k;
    	ll lo = 1, hi = LLONG_MAX, ans = -1;
        while (lo <= hi) {
            ll mid = lo + (hi - lo) / 2;
            ll gtri = xuli(a, mid);

            if (gtri >= k) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        cout << ans;

    }

}


