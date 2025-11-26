#include <bits/stdc++.h>
using namespace std;

struct Aho {
    static const int A = 26;
    struct Node {
        int nxt[A], link = -1, out = 0;
        Node() { memset(nxt, -1, sizeof nxt); }
    };

    vector<Node> t;

    Aho() { t.emplace_back(); }

    void add(string &s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) {
                t[u].nxt[x] = t.size();
                t.emplace_back();
            }
            u = t[u].nxt[x];
        }
        t[u].out++;
    }

    void build() {
        queue<int> q;
        t[0].link = 0;

        for (int c = 0; c < A; c++) {
            int v = t[0].nxt[c];
            if (v != -1) {
                t[v].link = 0;
                q.push(v);
            } else t[0].nxt[c] = 0;
        }

        while (!q.empty()) {
            int u = q.front(); q.pop();

            t[u].out += t[t[u].link].out;

            for (int c = 0; c < A; c++) {
                int v = t[u].nxt[c];
                if (v != -1) {
                    t[v].link = t[t[u].link].nxt[c];
                    q.push(v);
                } else
                    t[u].nxt[c] = t[t[u].link].nxt[c];
            }
        }
    }
};
