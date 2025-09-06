// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int mod = 1e9+7;
int n;
string grid[100005];
int64 dp[100005];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    f0(i,1,n){
        cin>>grid[i];
        grid[i] = " " + grid[i];
    }

    f0(i,1,n){
        f0(j,1,n){
            if(i==1 && j==1){
                dp[j] = (grid[i][j] == '.');
            } else if(grid[i][j] == '*'){
                dp[j] = 0;
            } else {
                dp[j] = ((j>1 ? dp[j-1] : 0) + dp[j]) % mod;
            }
        }
    }

    cout << dp[n] % mod;
}
