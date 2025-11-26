#include <bits/stdc++.h>
using namespace std;

struct SAM {
    struct State {
        int link, next[26], len;
        State() {
            link = -1;
            len = 0;
            memset(next, -1, sizeof next);
        }
    };

    vector<State> st;
    int last;

    SAM() {
        st.resize(1);
        last = 0;
    }

    void extend(char c) {
        int x = c - 'a';
        int cur = st.size();
        st.push_back(State());
        st[cur].len = st[last].len + 1;

        int p = last;
        while (p != -1 && st[p].next[x] == -1) {
            st[p].next[x] = cur;
            p = st[p].link;
        }

        if (p == -1) st[cur].link = 0;
        else {
            int q = st[p].next[x];
            if (st[p].len + 1 == st[q].len) st[cur].link = q;
            else {
                int clone = st.size();
                st.push_back(st[q]);
                st[clone].len = st[p].len + 1;

                while (p != -1 && st[p].next[x] == q) {
                    st[p].next[x] = clone;
                    p = st[p].link;
                }

                st[q].link = st[cur].link = clone;
            }
        }

        last = cur;
    }
};
