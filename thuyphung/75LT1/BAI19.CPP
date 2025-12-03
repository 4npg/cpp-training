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
    /*
    inp
    3
    0 5
    3 2
    10 3
    out
    13
    */
    int n;
    cin >> n;
    int curTime = 0;
    FOR(i, 1, n) {
        int a, d;
        cin >> a >> d;
        curTime = max(curTime, a);
        curTime += d;
    }
    cout << curTime;
}
