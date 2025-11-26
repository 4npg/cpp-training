#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

int a[MAXN], cnt[1000006], curAns = 0;
int BLOCK;

struct Query {
    int l, r, id;
    bool operator<(const Query &other) const {
        if (l / BLOCK != other.l / BLOCK) return l < other.l;
        return (l / BLOCK & 1) ? r < other.r : r > other.r;
    }
};

void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1) curAns++;
}

void remove(int x) {
    cnt[x]--;
    if (cnt[x] == 0) curAns--;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    BLOCK = sqrt(n);

    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<Query> qs(q);
    for (int i = 0; i < q; i++) {
        cin >> qs[i].l >> qs[i].r;
        qs[i].id = i;
    }

    sort(qs.begin(), qs.end());

    vector<int> ans(q);
    int L = 1, R = 0;

    for (auto &qr : qs) {
        while (L > qr.l) add(a[--L]);
        while (R < qr.r) add(a[++R]);
        while (L < qr.l) remove(a[L++]);
        while (R > qr.r) remove(a[R--]);

        ans[qr.id] = curAns;
    }

    for (int x : ans) cout << x << "\n";
}
