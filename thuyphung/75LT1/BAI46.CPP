#include <bits/stdc++.h>
using namespace std;
#define ll long long
string can[10] = {"Giáp", "Ất", "Bính", "Đinh", "Mậu", "Kỷ", "Canh", "Tân", "Nhâm", "Quý"};
string chi[12] = {"Tí", "Sửu", "Dần", "Mão", "Thìn", "Tỵ", "Ngọ", "Mùi", "Thân", "Dậu", "Tuất", "Hợi"};

ll getCan(ll y) {
    ll res = (2 + (y - 2006)) % 10;
    if (res < 0) res += 10;
    return res;
}

ll getChi(ll y) {
    ll res = (10 + (y - 2006)) % 12;
    if (res < 0) res += 12;
    return res;
}

int32_t main() {
    ll n; 
    string s;
    cin >> n >> s;

    ll ans = -1;
    ll minDist = LLONG_MAX;

    for (ll year = 100; year <= 10000; year++) {
        ll c = getCan(year);
        ll ch = getChi(year);
        if (can[c] == s || chi[ch] == s) {
            ll dist = abs(year - n);
            if (dist < minDist) {
                minDist = dist;
                ans = year;
            } else if (dist == minDist && year < ans) {
                ans = year;
            }
        }
    }

    cout << ans;
}
