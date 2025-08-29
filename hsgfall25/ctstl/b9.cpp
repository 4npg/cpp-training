#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define TASK "tenbai"
#define fi first 
#define se second
int main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    int n;
    int64 x;
    cin >> n >> x;
    vector<pair<int64,int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi;
        a[i].se = i + 1;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        int l = i + 1, r = n - 1;
        // hai con tro
        while (l < r) {
            int64 sum = a[i].fi + a[l].fi + a[r].fi;
            if (sum == x) {
                cout << a[i].se << " " << a[l].se << " " << a[r].se;
                return 0;
            }
            if (sum < x) l++;
            else r--;
        }
    }
    cout << "IMPOSSIBLE";
}
