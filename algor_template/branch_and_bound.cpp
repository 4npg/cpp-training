#include <bits/stdc++.h>
using namespace std;

/*
 Branch and Bound skeleton:
 - Maintain current partial solution + optimistic bound
 - Prune when bound >= best
*/

int n;
vector<vector<int>> cost;
vector<bool> used;
int best = INT_MAX;

void dfs_bb(int node, int depth, int cur, int optimistic){
    if (optimistic >= best) return;
    if (depth == n){
        best = min(best, cur + cost[node][0]); // example: return to start
        return;
    }
    for(int v=0;v<n;v++){
        if(!used[v]){
            used[v]=true;
            int newCur = cur + cost[node][v];
            // compute new optimistic bound (e.g. newCur + minimal remaining edges estimation)
            int newOpt = newCur; // placeholder
            dfs_bb(v, depth+1, newCur, newOpt);
            used[v]=false;
        }
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }
