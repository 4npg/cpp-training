#include <bits/stdc++.h>
using namespace std;

/*
 Mo's algorithm with updates (also called Mo's with modifications)

 Query:
   type = 1: query on range [l, r]
   type = 2: update a[pos] = newVal

 Complexity:
   O((N + Q) * sqrt(N) * F)
   F = cost add/remove
*/

struct Query {
    int l, r, t, id;
    bool operator<(const Query &other) const {
        if (block_l != other.block_l) return block_l < other.block_l;
        if (block_r != other.block_r) return block_r < other.block_r;
        return t < other.t;
    }
    int block_l, block_r;
};

struct Update {
    int pos, prev, now;
};

const int MAXN = 200005;

int n, q;
int a[MAXN];
int BLOCK;

vector<Query> queries;
vector<Update> updates;

long long ans[MAXN];

// ------------ CUSTOM ADD / REMOVE ------------------

long long cnt[1000006];
long long curAns = 0;

void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1) curAns++;
}

void remove(int x) {
    cnt[x]--;
    if (cnt[x] == 0) curAns--;
}

// ------------------------------------------------------

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];

    BLOCK = pow(n, 2.0/3.0);

    int t = 0; // số update đã lưu

    for (int i = 0; i < q; i++) {
        char type;
        cin >> type;

        if (type == 'Q') {
            int l, r;
            cin >> l >> r;
            Query qr;
            qr.l = l;
            qr.r = r;
            qr.t = t;
            qr.id = queries.size();
            qr.block_l = l / BLOCK;
            qr.block_r = r / BLOCK;
            queries.push_back(qr);
        }
        else { // type == 'U'
            int pos, val;
            cin >> pos >> val;
            Update u;
            u.pos = pos;
            u.prev = a[pos];
            u.now = val;
            a[pos] = val;
            updates.push_back(u);
            t++;
        }
    }

    // reset array a
    for (int i = 0; i < t; i++) {
        a[updates[i].pos] = updates[i].prev;
    }

    sort(queries.begin(), queries.end());

    int L = 1, R = 0, T = 0;

    for (auto &qr : queries) {
        int l = qr.l;
        int r = qr.r;

        // ---- adjust time (apply updates or rollback) ----
        while (T < qr.t) {
            int pos = updates[T].pos;
            if (L <= pos && pos <= R) {
                remove(a[pos]);
                add(updates[T].now);
            }
            a[pos] = updates[T].now;
            T++;
        }

        while (T > qr.t) {
            T--;
            int pos = updates[T].pos;
            if (L <= pos && pos <= R) {
                remove(a[pos]);
                add(updates[T].prev);
            }
            a[pos] = updates[T].prev;
        }

        // ----- adjust L, R -----
        while (R < r) add(a[++R]);
        while (L > l) add(a[--L]);
        while (R > r) remove(a[R--]);
        while (L < l) remove(a[L++]);

        ans[qr.id] = curAns;
    }

    for (int i = 0; i < (int)queries.size(); i++)
        cout << ans[i] << "\n";
}
