#include <bits/stdc++.h>
using namespace std;

vector<int> buildSA(string s) {
    s += '$';
    int n = s.size();
    vector<int> sa(n), c(n);

    vector<pair<char,int>> a(n);
    for (int i = 0; i < n; i++) a[i] = {s[i], i};
    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) sa[i] = a[i].second;
    c[sa[0]] = 0;
    for (int i = 1; i < n; i++)
        c[sa[i]] = c[sa[i-1]] + (a[i].first != a[i-1].first);

    int k = 0;
    vector<int> sa_new(n), c_new(n);

    while ((1 << k) < n) {
        for (int i = 0; i < n; i++)
            sa[i] = (sa[i] - (1 << k) + n) % n;

        int cnt = *max_element(c.begin(), c.end()) + 1;
        vector<int> bucket(cnt, 0);

        for (int x : c) bucket[x]++;
        for (int i = 1; i < cnt; i++) bucket[i] += bucket[i-1];

        for (int i = n-1; i >= 0; i--)
            sa_new[--bucket[c[sa[i]]]] = sa[i];

        sa = sa_new;

        c_new[sa[0]] = 0;
        for (int i = 1; i < n; i++) {
            pair<int,int> cur = {c[sa[i]], c[(sa[i] + (1<<k)) % n]};
            pair<int,int> prev = {c[sa[i-1]], c[(sa[i-1] + (1<<k)) % n]};
            c_new[sa[i]] = c_new[sa[i-1]] + (cur != prev);
        }
        c = c_new;
        k++;
    }

    return sa;
}

vector<int> buildLCP(string s, vector<int>& sa) {
    int n = s.size();
    vector<int> rank(n), lcp(n);
    for (int i = 0; i < n; i++) rank[sa[i]] = i;

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (rank[i] == 0) continue;
        int j = sa[rank[i] - 1];
        while (i+k < n && j+k < n && s[i+k] == s[j+k]) k++;
        lcp[rank[i]] = k;
        if (k) k--;
    }
    return lcp;
}
