#include <bits/stdc++.h>
using namespace std;

struct DSURollback {
    vector<int> parent, sz;
    vector<pair<int,int>> stk;
    DSURollback(int n): parent(n+1), sz(n+1,1){
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int x){ while(parent[x]!=x) x=parent[x]; return x; }
    void unite(int a,int b){
        a = find(a); b = find(b);
        if(a==b){ stk.emplace_back(-1,-1); return; }
        if(sz[a] < sz[b]) swap(a,b);
        parent[b]=a; sz[a]+=sz[b];
        stk.emplace_back(a,b);
    }
    void rollback(){
        auto p = stk.back(); stk.pop_back();
        if(p.first == -1) return;
        int a = p.first, b = p.second;
        sz[a] -= sz[b];
        parent[b] = b;
    }
};

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }
