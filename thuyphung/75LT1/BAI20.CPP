// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)

struct Circle {
    int x, y, r;
};

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }
    /*
    y tuong : abs(r1-r2)<d<r1+r2
    voi r la khoang cach giua 2 tam duong tron
    inp
    4
	0 0 2
	4 0 2
	2 0 1
	10 0 1
	out
	2
	*/
    int n;
    cin >> n;
    vector<Circle> a(n);
    FOR(i, 0, n - 1) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }

    int res = 0;
    FOR(i, 0, n - 1) {
        FOR(j, i + 1, n - 1) {
            int64 dx = a[i].x - a[j].x;
            int64 dy = a[i].y - a[j].y;
            int64 dist2 = dx * dx + dy * dy;

            int64 sumR = a[i].r + a[j].r;
            int64 diffR = abs(a[i].r - a[j].r);

            if (diffR * diffR < dist2 && dist2 < sumR * sumR)
                ++res;
        }
    }

    cout << res;
}
