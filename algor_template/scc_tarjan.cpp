#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;

vector<int> adj[MAXN];
int n, m;

int timer = 0, scc_cnt = 0;
int low[MAXN], num[MAXN];
bool inStack[MAXN];
stack<int> st;

void dfs(int u) {
    num[u] = low[u] = ++timer;
    st.push(u);
    inStack[u] = true;

    for (int v : adj[u]) {
        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        } 
        else if (inStack[v]) {
            low[u] = min(low[u], num[v]);
        }
    }

    if (low[u] == num[u]) {
        ++scc_cnt;
        while (1) {
            int v = st.top(); st.pop();
            inStack[v] = false;
            // v thuộc scc thứ scc_cnt
            if (v == u) break;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    for (int i = 1; i <= n; i++)
        if (!num[i]) dfs(i);

    cout << scc_cnt;
}
