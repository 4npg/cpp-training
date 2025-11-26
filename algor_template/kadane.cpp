// author: anphung
#include <bits/stdc++.h>
using namespace std;

// --------------------------------------------------------
// KADANE ALGORITHM
// Tìm max subarray sum trong O(n)
// --------------------------------------------------------

long long kadane_basic(const vector<long long>& a) {
    long long best = LLONG_MIN;
    long long cur = 0;
    for (long long x : a) {
        cur = max(x, cur + x);
        best = max(best, cur);
    }
    return best;
}

// --------------------------------------------------------
// KADANE + TRUY VẾT ĐOẠN (l, r)
// Trả về: {bestSum, leftIndex, rightIndex}
// --------------------------------------------------------

tuple<long long,int,int> kadane_trace(const vector<long long>& a) {
    long long best = LLONG_MIN, cur = 0;
    int start = 0, L = 0, R = 0;

    for (int i = 0; i < (int)a.size(); i++) {
        if (cur + a[i] < a[i]) {
            cur = a[i];
            start = i;           // bắt đầu đoạn mới
        } else {
            cur += a[i];
        }

        if (cur > best) {
            best = cur;
            L = start;
            R = i;
        }
    }
    return {best, L, R};
}

// --------------------------------------------------------
// KADANE CHO TRƯỜNG HỢP HOÀN TOÀN ÂM
// DÙNG CHUNG HÀM BASIC VẪN ĐƯỢC
// --------------------------------------------------------

// nêu mảng toàn âm, kadane_basic vẫn trả về max phần tử
// không cần viết riêng

// --------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> a = { -2, 1, -3, 4, -1, 2, 1, -5, 4 };

    cout << "Kadane basic = " << kadane_basic(a) << "\n";

    auto [best, L, R] = kadane_trace(a);
    cout << "Kadane trace: sum = " << best
         << ", from " << L << " to " << R << "\n";
}
