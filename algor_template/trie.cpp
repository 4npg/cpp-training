#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        int cnt;
        int nxt[26];
        Node() {
            cnt = 0;
            memset(nxt, -1, sizeof nxt);
        }
    };

    vector<Node> t;

    Trie() {
        t.emplace_back(); // root
    }

    void insert(const string &s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) {
                t[u].nxt[x] = t.size();
                t.emplace_back();
            }
            u = t[u].nxt[x];
        }
        t[u].cnt++;
    }

    int query(const string &s) {
        int u = 0;
        for (char c : s) {
            int x = c - 'a';
            if (t[u].nxt[x] == -1) return 0;
            u = t[u].nxt[x];
        }
        return t[u].cnt;
    }
};
