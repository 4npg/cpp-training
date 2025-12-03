#include <bits/stdc++.h>
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,fma")
using namespace std;
# define ll long long
# define endl "\n"
# define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
const ll maxn = 1e7*1ll;
ll d[maxn];
int main(){
    fast;
    ll n;cin>>n;
    vector<ll>a(n);
    for(ll i=0;i<n;i++)cin>>a[i];
    for (ll res = 1; res <= n; res++) {
	    if (n % res != 0) continue;

	    bool ok = true;
	    for (ll i = 0; i < n; i++) {
	        if (a[i] != a[i % res]) {
	            ok = false;
	            break;
	        }
	    }

	    if (ok) {
	        cout << res << "\n";
	        return 0;
	    }
	}

}       