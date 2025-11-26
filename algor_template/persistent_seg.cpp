#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

struct Node {
    int sum;
    Node *l, *r;
    Node(int s=0, Node* l=nullptr, Node* r=nullptr): sum(s), l(l), r(r) {}
};

Node* build(int l, int r) {
    if (l == r) return new Node();
    int mid = (l + r) >> 1;
    return new Node(0, build(l, mid), build(mid+1, r));
}

Node* update(Node* pre, int l, int r, int pos) {
    if (l == r) return new Node(pre->sum + 1);
    int mid = (l + r) >> 1;
    if (pos <= mid)
        return new Node(pre->sum+1, update(pre->l, l, mid, pos), pre->r);
    else
        return new Node(pre->sum+1, pre->l, update(pre->r, mid+1, r, pos));
}

int query(Node* a, Node* b, int l, int r, int k) {
    if (l == r) return l;
    int mid = (l + r) >> 1;
    int leftCnt = a->l->sum - b->l->sum;
    if (k <= leftCnt)
        return query(a->l, b->l, l, mid, k);
    return query(a->r, b->r, mid+1, r, k-leftCnt);
}
