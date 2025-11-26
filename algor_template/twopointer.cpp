#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, target;
    cin >> n >> target;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    int l = 0, sum = 0, ans = 0;

    for (int r = 0; r < n; r++) {
        sum += a[r];

        while (sum > target) {
            sum -= a[l++];
        }

        ans = max(ans, r - l + 1);
    }

    cout << ans;
    return 0;
}
