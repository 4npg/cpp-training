// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    /* test
    inp
	5
	1 3
	2 7
	3 2
	4 6
	5 4
	out
	8
	*/
    int n;
    cin >> n;
    vector<int> y(n);
    FOR(i, 0, n-1) {
        int x;
        cin >> x >> y[i];
    }

    sort(y.begin(), y.end());
    int median = y[n/2];
    int64 res = 0;
    FOR(i, 0, n-1) res += abs(y[i] - median);
    cout << res;
}
