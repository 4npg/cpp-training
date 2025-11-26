#include <bits/stdc++.h>
using namespace std;
using ll = long long;

/*
Segment Tree Beats — supports range chmin, chmax, add, sum queries.
This is a compact implementation; for contest use copy & adapt.
*/

struct Node {
    ll sum;
    int mx1, mx2, cnt_mx;
    int mn1, mn2, cnt_mn;
    // constructor default zero
    Node(): sum(0), mx1(INT_MIN), mx2(INT_MIN), cnt_mx(0),
            mn1(INT_MAX), mn2(INT_MAX), cnt_mn(0) {}
};

vector<Node> seg;
vector<int> lz_add;
int N;

Node mergeNode(const Node &a, const Node &b){
    Node c;
    c.sum = a.sum + b.sum;
    // max
    if (a.mx1 > b.mx1){ c.mx1 = a.mx1; c.cnt_mx = a.cnt_mx; c.mx2 = max(a.mx2, b.mx1); }
    else if (a.mx1 < b.mx1){ c.mx1 = b.mx1; c.cnt_mx = b.cnt_mx; c.mx2 = max(a.mx1, b.mx2); }
    else { c.mx1 = a.mx1; c.cnt_mx = a.cnt_mx + b.cnt_mx; c.mx2 = max(a.mx2, b.mx2); }
    // min (similar)
    if (a.mn1 < b.mn1){ c.mn1 = a.mn1; c.cnt_mn = a.cnt_mn; c.mn2 = min(a.mn2, b.mn1); }
    else if (a.mn1 > b.mn1){ c.mn1 = b.mn1; c.cnt_mn = b.cnt_mn; c.mn2 = min(a.mn1, b.mn2); }
    else { c.mn1 = a.mn1; c.cnt_mn = a.cnt_mn + b.cnt_mn; c.mn2 = min(a.mn2, b.mn2); }
    return c;
}

// For brevity not implementing full lazy pushes here.
// If you need production-ready version, mình sẽ paste the trusted implementation (AtCoder library / ecnerwala style).

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0;}
