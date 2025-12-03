// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

bool covered[201][201];

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    /*
    inp 
    3
	0 2 2 0
	1 3 3 1
	-1 1 1 -1
	out
	10
	*/
    int n;
    cin >> n;
    FOR(i, 1, n) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        if (x1 > x2) swap(x1, x2);
        if (y1 < y2) swap(y1, y2);

        for (int x = x1; x < x2; ++x)
            for (int y = y2 + 100; y < y1 + 100; ++y)
                covered[x + 100][y] = true;
    }

    int res = 0;
    FOR(x, 0, 200)
        FOR(y, 0, 200)
            res += covered[x][y];

    cout << res;
}
