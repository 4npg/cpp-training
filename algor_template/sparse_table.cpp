#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
int st[20][MAXN];
int lg[MAXN];
int n;

int query(int l, int r) {
    int k = lg[r - l + 1];
    return min(st[k][l], st[k][r - (1 << k) + 1]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> st[0][i];

    lg[1] = 0;
    for (int i = 2; i < MAXN; i++)
        lg[i] = lg[i/2] + 1;

    for (int k = 1; k < 20; k++)
        for (int i = 1; i + (1 << k) - 1 <= n; i++)
            st[k][i] = min(st[k-1][i], st[k-1][i + (1 << (k-1))]);
}
