#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<int> tin, tout, flat;
int timer=0;

void dfs(int u,int p){
    tin[u]=++timer;
    flat[timer]=u;
    for(int v: g[u]) if(v!=p) dfs(v,u);
    tout[u]=timer;
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }
