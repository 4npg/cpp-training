#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    ll target;
    cin >> n >> target;

    vector<ll> a(n);
    for (ll &x : a) cin >> x;

    int mid = n / 2;

    vector<ll> L, R;

    // Tạo tất cả subset sum nửa trái
    for (int mask = 0; mask < (1 << mid); mask++) {
        ll s = 0;
        for (int i = 0; i < mid; i++)
            if (mask & (1 << i)) s += a[i];
        L.push_back(s);
    }

    // Nửa phải
    int rlen = n - mid;
    for (int mask = 0; mask < (1 << rlen); mask++) {
        ll s = 0;
        for (int i = 0; i < rlen; i++)
            if (mask & (1 << i)) s += a[mid + i];
        R.push_back(s);
    }

    sort(R.begin(), R.end());

    long long countWays = 0;

    for (ll x : L) {
        ll need = target - x;
        auto l = lower_bound(R.begin(), R.end(), need);
        auto r = upper_bound(R.begin(), R.end(), need);
        countWays += (r - l);
    }

    cout << countWays;
    return 0;
}
