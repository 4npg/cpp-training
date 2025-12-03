#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)
#define ll long long
#define oo 1e18
int main(){
    fast;
    ll n, k;
    cin >> n >> k;
    vector<vector<ll>> a(n+1, vector<ll>(n+1));
    for(ll i = 1; i <= n; i++){
        for(ll j = 1; j <= n; j++){
            cin >> a[i][j];
        }
    }

    ll M = n - k + 1;
    vector<vector<ll>> rowSum(n+1, vector<ll>(M+1, 0));
    for(ll i = 1; i <= n; i++){
        ll cur = 0;
        for(ll j = 1; j <= k; j++){
            cur += a[i][j];
        }
        rowSum[i][1] = cur;
        for(ll j = 2; j <= M; j++){
            cur = cur +  a[i][j+k-1] - a[i][j-1];
            rowSum[i][j] = cur;
        }
    }

    ll res = -oo;
    for(ll j = 1; j <= M; j++){
        ll cur = 0;
        for(ll i = 1; i <= k; i++){
            cur += rowSum[i][j];
        }
        res = max(res, cur);
        for(ll i = 2; i <= M; i++){
            cur += rowSum[i+k-1][j];
            cur -= rowSum[i-1][j];
            res = max(res, cur);
        }
    }

    cout << res;
}
