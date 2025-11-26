#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;

const ull BASE = 131;
const int MAXN = 2000005;

ull h[MAXN], pw[MAXN];

void build_hash(const string &s) {
    int n = s.size();
    pw[0] = 1;

    for (int i = 1; i <= n; i++)
        pw[i] = pw[i-1] * BASE;

    for (int i = 1; i <= n; i++)
        h[i] = h[i-1] * BASE + s[i-1];
}

ull get_hash(int l, int r) { // 1-index
    return h[r] - h[l-1] * pw[r-l+1];
}

int main() {
    string s;
    cin >> s;

    build_hash(s);

    return 0;
}
