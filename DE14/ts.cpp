// author: anphung (4npg)
// bai: Chu X lon nhat
#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int MAXN = 505; // tuỳ đề cho giới hạn
int n;
int a[MAXN][MAXN];

// trả về tổng đoạn [l..r] từ mảng prefix
int getSum(const vector<int> &v, int l, int r) {
    return v[r] - (l ? v[l-1] : 0);
}

// xây prefix sum cho tất cả vector trong 1 mảng chéo
void buildPrefix(vector<vector<int>> &diag) {
    for (auto &v : diag)
        for (int i = 1; i < (int)v.size(); i++)
            v[i] += v[i-1];
}

// tính hiệu (chéo chính - chéo phụ) của ma trận con (x,y,k)
int calcDiff(int x, int y, int k, int offset,
             vector<vector<int>> &chinh, vector<vector<int>> &phu,
             vector<vector<int>> &posc, vector<vector<int>> &posp) {
    int idc = x - y + offset;
    int pc = posc[x][y];
    int tongc = getSum(chinh[idc], pc, pc + k - 1);

    int idp = x + (y + k - 1);
    int pp = posp[x][y + k - 1];
    int tongp = getSum(phu[idp], pp, pp + k - 1);

    return tongc - tongp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    int offset = n - 1;
    vector<vector<int>> chinh(2*n), phu(2*n);
    vector<vector<int>> posc(n, vector<int>(n)), posp(n, vector<int>(n));

    // gom các phần tử vào chéo
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int idc = i - j + offset;
            posc[i][j] = chinh[idc].size();
            chinh[idc].pb(a[i][j]);

            int idp = i + j;
            posp[i][j] = phu[idp].size();
            phu[idp].pb(a[i][j]);
        }
    }

    // build prefix
    buildPrefix(chinh);
    buildPrefix(phu);

    int ans = -1e9;
    for (int x = 0; x < n; x++) {
        for (int y = 0; y < n; y++) {
            int maxK = min(n - x, n - y);
            for (int k = 2; k <= maxK; k++) {
                ans = max(ans, calcDiff(x, y, k, offset, chinh, phu, posc, posp));
            }
        }
    }

    cout << ans << "\n";
}
