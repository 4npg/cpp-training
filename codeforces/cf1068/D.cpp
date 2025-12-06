// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define inf (int64)4e18

void solve(){
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
        if(x > k) x = k;
    }


    vector<bool> useful(n, false);
    for(int v = 1; v <= k; ++v){
        int limit = k / v; 
        int cnt = 0;
        for(int i = 0; i < n; ++i){
            if(a[i] >= v){
                useful[i] = true;
                cnt++;
                if(cnt >= limit) break;
            }
        }
    }

    vector<vector<int64>> dp(k + 1, vector<int64>(k + 1, -inf));
    
    for(int t = 0; t <= k; ++t) dp[t][0] = 0; 

    vector<vector<int64>> next_dp(k + 1, vector<int64>(k + 1));
    vector<int64> G(k + 2);  
    vector<int64> sufMax(k + 2); 

    int lazy = 0;

    for(int i = n - 1; i >= 0; --i){
        lazy++; 
        
        if(!useful[i]) continue;

        int cap = a[i]; 
        
        
        for(int t = 0; t <= k; ++t) {
            for(int c = 0; c <= k; ++c) {
                next_dp[t][c] = dp[t][c];
            }
        }

       
        for(int c = 1; c <= k; ++c){
            int lim = min(c, cap); 
            sufMax[lim + 1] = -inf;
            
            for(int x = lim; x >= 1; --x){
                int64 val = dp[x][c-x];
                if(val > -inf/2) {
                    G[x] = val + (int64)x * lazy;
                } else {
                    G[x] = -inf;
                }
                sufMax[x] = max(sufMax[x+1], G[x]);
            }
            for(int t = 0; t < lim; ++t){
                if(sufMax[t+1] > -inf/2){
                    int64 cand = sufMax[t+1] - (int64)t * lazy;
                    if(cand > next_dp[t][c]) next_dp[t][c] = cand;
                }
            }
        }
        
        for(int t=0; t<=k; ++t){
            for(int c=0; c<=k; ++c){
                dp[t][c] = next_dp[t][c];
            }
        }
    }

    int64 ans = 0;

    for(int c = 0; c <= k; ++c) ans = max(ans, dp[0][c]);
    cout << ans << '\n';
}

int32_t main(){
    ios::sync_with_stdio(0); 
    cin.tie(0);
    int q;
    cin >> q;
    while(q--){
        solve();
    }
    return 0;
}