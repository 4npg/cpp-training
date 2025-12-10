#include <bits/stdc++.h>
#define ll long long
#define FOR(i,a,b) for(int i=a;i<=b;i++)
using namespace std;

const ll NEG = -4e18;
ll a[100005], b[100005], dp[100005][4];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    FOR(i,1,n) cin >> a[i];
    FOR(i,1,n) cin >> b[i];

    dp[1][0] = a[1];
    dp[1][1] = NEG;
    dp[1][2] = b[1];
    dp[1][3] = NEG;

    FOR(i,2,n){
        cerr<<'\n';
        cerr<<"truoc "<<dp[i][0]<<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<'\n';
        dp[i][0] = max(dp[i-1][2], dp[i-1][3]) + a[i];
        dp[i][1] = dp[i-1][0] + a[i];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + b[i];
        dp[i][3] = dp[i-1][2] + b[i];
        
        cerr << "sau "<<dp[i][0] <<" "<<dp[i][1]<<" "<<dp[i][2]<<" "<<dp[i][3]<<'\n';
    }

    cout << max({dp[n][0], dp[n][1], dp[n][2], dp[n][3]});
}