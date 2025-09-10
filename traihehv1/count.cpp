#include<bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define FORD(i, b, a) for (int i = (b), _a = (a); i >= _a; i--)
#define REP(i, n) for (int i = 0, _n = (n); i < _n; i++)

#define ALL(v)   (v).begin(), (v).end()
#define fi   first
#define se   second

#define MASK(i) (1LL << (i))
#define BIT(x, i) (((x) >> (i)) & 1)

template<class X, class Y>
    bool minimize(X &x, const Y &y) {
        if (x > y) {
            x = y;
            return true;
        } else return false;
    }

template<class X, class Y>
    bool maximize(X &x, const Y &y) {
        if (x < y) {
            x = y;
            return true;
        } else return false;
    }

struct SegmentTree {
    vector<int> minValue, minCount, lazy;
    int n;

    void build(int i, int l, int r) {
        minCount[i] = r - l + 1;
        if (l == r) return;
        int m = (l + r) >> 1;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
    }

    SegmentTree(int _n = 0) {
        n = _n;
        minValue.assign(4 * n + 7, 0);
        minCount.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
        build(1, 1, n);
    }

    void pushDown(int i) {
        if (lazy[i] == 0) return;
        FOR(j, 2 * i, 2 * i + 1) {
            minValue[j] += lazy[i];
            lazy[j] += lazy[i];
        }
        lazy[i] = 0;
    }

    void update(int i, int l, int r, int u, int v, int c) {
        if (l > v || r < u || l > r || v < u) return;
        if (u <= l && r <= v) {
            minValue[i] += c;
            lazy[i] += c;
            return;
        }

        pushDown(i);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        minValue[i] = min(minValue[2 * i], minValue[2 * i + 1]);
        minCount[i] = (minValue[2 * i] == minValue[i] ? minCount[2 * i] : 0) + (minValue[2 * i + 1] == minValue[i] ? minCount[2 * i + 1] : 0);
    }

    void update(int l, int r, int c) {
        update(1, 1, n, l, r, c);
    }

    int getNumZero(void) const {
        return minValue[1] == 0 ? minCount[1] : 0;
    }
};

struct Update {
    int fr, to, delta;

    Update(int _fr = 0, int _to = 0, int _delta = 0) {
        fr = _fr; to = _to; delta = _delta;
    }
};

#define MAX   100100
int n, m, a[MAX];

void init(void) {
    scanf("%d%d", &n, &m);
    FOR(i, 1, n) scanf("%d", &a[i]);
}

namespace subtask1 {
    int cnt[MAX], cntOfCnt[MAX];

    bool check(void) {
        return n <= 1000;
    }

    void process(void) {
        int res = 0;
        FOR(l, 1, n) {
            memset(cnt, 0, (n + 1) * sizeof (int));
            memset(cntOfCnt, 0, (n + 1) * sizeof (int));
            cntOfCnt[0] = n;

            FOR(r, l, n) {
                cntOfCnt[cnt[a[r]]]--;
                cnt[a[r]]++;
                cntOfCnt[cnt[a[r]]]++;

                bool ok = true;
                FOR(i, 1, m) if (cntOfCnt[i] == 0) ok = false;
                if (ok) res++;
            }
        }

        printf("%d\n", res);
    }
}

namespace subtask2 {
    bool check(void) {
        FOR(i, 1, n) if (a[i] > m) return false;
        return true;
    }

    int cnt[10], have[10];

    void process(void) {
        int res = 0;
        FOR(i, 1, n) if (i + m * (m + 1) / 2 - 1 <= n) {
            int j = i + m * (m + 1) / 2 - 1;
            memset(cnt, 0, sizeof cnt);
            memset(have, 0, sizeof have);
            FOR(k, i, j) cnt[a[k]]++;
            FOR(k, 1, m) have[cnt[k]]++;

            bool ok = true;
            FOR(k, 1, m) if (have[k] == 0) ok = false;
            if (ok) res++;
        }
        printf("%d\n", res);
    }
}

namespace subtask4 {
    bool check(void) {
        return true;
    }

    vector<int> pos[MAX];
    vector<Update> updates[5][MAX];

    void addRectangle(int id, int minX, int maxX, int minY, int maxY) {
        updates[id][minX].push_back(Update(minY, maxY, +1));
        updates[id][maxX + 1].push_back(Update(minY, maxY, -1));
    }

    void prepare(void) {
        FOR(i, 1, n) pos[a[i]].push_back(i);
        FOR(i, 1, n) {
            vector<int> &v = pos[i];
            v.insert(v.begin(), 0);
            v.push_back(n + 1);

            FOR(j, 1, v.size() - 2) REP(k, m) if (j + k <= (int)v.size() - 2)
                addRectangle(k + 1, v[j - 1] + 1, v[j], v[j + k], v[j + k + 1] - 1);
        }
    }

    long long countNumber(int mask) {
        SegmentTree myit(n);
        long long res = 0;
        FOR(i, 1, n) {
            FOR(j, 1, m) if (BIT(mask, j - 1)) {
                for (const Update &u : updates[j][i]) myit.update(u.fr, u.to, u.delta);
            }
            res += myit.getNumZero();
        }

        return res - 1LL * n * (n - 1) / 2;
    }

    void process(void) {
        prepare();

        long long res = 1LL * n * (n + 1) / 2;
        FOR(mask, 1, MASK(m) - 1) {
            long long tmp = countNumber(mask);
            if (__builtin_popcount(mask) % 2 == 0) res += tmp;
            else res -= tmp;
        }
        cout << res << "\n";
    }
}

int main(void) {
    init();
    if (subtask1::check()) return subtask1::process(), 0;
    if (subtask2::check()) return subtask2::process(), 0;
    if (subtask4::check()) return subtask4::process(), 0;
    return 0;
}
