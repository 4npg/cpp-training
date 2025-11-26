#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Line {
    ll a, b;
    ll get(ll x) { return a * x + b; }
};

struct LiChao {
    struct Node { Line ln; Node *l, *r; };
    ll L, R;
    Node* root;

    LiChao(ll L, ll R):L(L),R(R),root(nullptr){}

    void addLine(Line v, Node*& nd, ll l, ll r) {
        if (!nd) {
            nd = new Node{v, nullptr, nullptr};
            return;
        }

        ll mid = (l + r) >> 1;

        bool left = v.get(l) < nd->ln.get(l);
        bool m = v.get(mid) < nd->ln.get(mid);

        if (m) swap(v, nd->ln);

        if (r - l == 1) return;

        if (left != m)
            addLine(v, nd->l, l, mid);
        else
            addLine(v, nd->r, mid, r);
    }

    void addLine(ll a, ll b) { addLine({a,b}, root, L, R); }

    ll query(ll x, Node* nd, ll l, ll r) {
        if (!nd) return LLONG_MAX;
        ll res = nd->ln.get(x);
        if (r - l == 1) return res;

        ll mid = (l + r) >> 1;
        if (x < mid) return min(res, query(x, nd->l, l, mid));
        return min(res, query(x, nd->r, mid, r));
    }

    ll query(ll x) { return query(x, root, L, R); }
};
