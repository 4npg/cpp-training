#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll y, k, n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("task.INP","r",stdin);
    freopen("task.OUT","w",stdout);

    cin >> y >> k >> n;

    ll maxx = n - y;

    if (maxx <= 0) {
        cout << -1;
        return 0;
    }


    bool ok = 0;

    ll r = (k - (y % k)) % k;
    if (r == 0) r = k;

    for (ll x = r; x <= maxx; x += k) {
        cout << x << " ";
        ok = 1;
    }
    if(!ok)cout<<-1;
    return 0;
}
