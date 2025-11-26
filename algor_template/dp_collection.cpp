#include <bits/stdc++.h>
using namespace std;

/* LIS — O(n log n) */
int LIS(vector<int> a){
    vector<int> tail;
    for(int x:a){
        auto it = lower_bound(tail.begin(), tail.end(), x);
        if(it==tail.end()) tail.push_back(x);
        else *it = x;
    }
    return (int)tail.size();
}

/* LCS classic O(n*m) */
int LCS(const string &a, const string &b){
    int n=a.size(), m=b.size();
    vector<int> dp(m+1,0), prev(m+1,0);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i-1]==b[j-1]) dp[j]=prev[j-1]+1;
            else dp[j]=max(prev[j], dp[j-1]);
        }
        prev=dp;
    }
    return dp[m];
}

/* Digit DP skeleton: count numbers <= bound with property */
long long digit_dp(const string &s){
    // dp[pos][tight][state] -> implement per problem
    return 0;
}

/* Bitmask DP example: TSP O(n^2 * 2^n) */
int tsp_bitmask(const vector<vector<int>>& w){
    int n = w.size();
    int FULL = 1<<n;
    const int INF = 1e9;
    vector<vector<int>> dp(FULL, vector<int>(n, INF));
    dp[1][0]=0;
    for(int mask=1; mask<FULL; ++mask){
        for(int u=0; u<n; ++u) if(mask & (1<<u)){
            for(int v=0; v<n; ++v) if(!(mask & (1<<v))){
                dp[mask | (1<<v)][v] = min(dp[mask | (1<<v)][v], dp[mask][u] + w[u][v]);
            }
        }
    }
    int ans = INF;
    for(int u=0; u<n; ++u) ans = min(ans, dp[FULL-1][u] + w[u][0]);
    return ans;
}

/* Tree DP skeleton (pair: include/exclude) */
int n;
vector<vector<int>> g;
vector<int> val;
vector<array<int,2>> dpT;
void dfs_tree(int u,int p){
    dpT[u][0]=0; dpT[u][1]=val[u];
    for(int v: g[u]) if(v!=p){
        dfs_tree(v,u);
        dpT[u][0] += dpT[v][1]; // example depending problem
        dpT[u][1] += min(dpT[v][0], dpT[v][1]);
    }
}

int main(){ ios::sync_with_stdio(false); cin.tie(nullptr); return 0; }
