#include <bits/stdc++.h>
using namespace std;

#define TASK "tenbai"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define ll long long

ll daysInMonth(ll m, ll y) {
    static ll d[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) return 29;
    return d[m - 1];
}

ll dateToDays(ll d, ll m, ll y) {
    ll days = 0;
    for (ll yy = 0; yy < y; ++yy)
        days += ((yy % 4 == 0 && yy % 100 != 0) || yy % 400 == 0) ? 366 : 365;
    for (ll mm = 1; mm < m; ++mm)
        days += daysInMonth(mm, y);
    return days + d;
}

void daysToDate(ll totalDays, ll &d, ll &m, ll &y) {
    y = 0;
    while (true) {
        ll daysInYear = ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) ? 366 : 365;
        if (totalDays < daysInYear) break;
        totalDays -= daysInYear;
        y++;
    }
    m = 1;
    while (true) {
        ll dim = daysInMonth(m, y);
        if (totalDays < dim) break;
        totalDays -= dim;
        m++;
    }
    d = totalDays + 1;
}

int32_t main() {
    fast;
    if (fopen(TASK ".inp", "r")) {
        freopen(TASK ".inp", "r", stdin);
        freopen(TASK ".out", "w", stdout);
    }

    ll dl, ml, yl, y;
    cin >> dl >> ml >> yl >> y;

    ll startDay = dateToDays(dl, ml, yl);
    ll from = dateToDays(1, 1, y);
    ll to = dateToDays(31, 12, y);

    bool found = false;

    for (ll t = from; t <= to; ++t) {
        ll delta = t - starptDay;
        if (delta < 0) continue;
        ll cnt = 0;
        if (delta % 23 == 0) cnt++;
        if (delta % 27 == 0) cnt++;
        if (delta % 33 == 0) cnt++;
        if (cnt >= 2) {
            ll d, m, yy;
            daysToDate(t, d, m, yy);
            cout << setw(2) << setfill('0') << d << '/'
                 << setw(2) << setfill('0') << m << '/'
                 << yy << '\n';
            found = true;
        }
    }

    if (!found) cout << "lucky\n";
}
