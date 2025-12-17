// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file "JUMP"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
//     return l+rng()%(r-l+1);
// }

#define maxn 1005
#define mod 1000000007

int n, m, d;
int a[maxn][maxn];
int64 rows[maxn][maxn];
int64 cols[maxn][maxn];
int dp[maxn][maxn];


void sub1(){
    f0(i, 1, n){
        f0(j, 1, m){
            if(i == 1 && j == 1)continue;
            int u = i-1;
            while(u>=1 && (cols[i][j] - cols[u-1][j] <= d)){
                dp[i][j] = (dp[i][j] + dp[u][j])%mod;
                u--;
            }

            int v = j-1;
            while(v>=1 && (rows[i][j] - rows[i][v-1] <= d)){
                dp[i][j] = (dp[i][j] + dp[i][v])%mod;
                v--;
            }
        }
    }

    cout<<dp[n][m]%mod;
}

i_love_Hoang_Ngan(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    freopen(file".inp", "r", stdin);
    //freopen(file".out", "w", stdout);

    cin>>n>>m>>d;

    f0(i, 1, n){
        string s; cin>>s;
        f0(j, 1, m){
            a[i][j] = s[j-1] - '0';
        }
    }

    f0(i, 1, n){
        f0(j, 1, m){
            rows[i][j] = rows[i][j-1] + a[i][j];
            cols[i][j] = cols[i-1][j] + a[i][j];
        }
    }

    dp[1][1] = 1;

    f0(i,1,n){
        deque<pair<int,int>> dq;
        int64 sum_window = 0;
        f0(j,1,m){
            while(!dq.empty() && (rows[i][j]-rows[i][dq.front().first-1] > d)){
                sum_window = (sum_window - dq.front().second + mod)%mod;
                dq.pop_front();
            }
            if(j>1){
                dq.push_back({j-1, dp[i][j-1]});
                sum_window = (sum_window + dp[i][j-1])%mod;
                dp[i][j] = (dp[i][j] + sum_window)%mod;
            }
        }
    }

    f0(j,1,m){
        deque<pair<int,int>> dq;
        int64 sum_window = 0;
        f0(i,1,n){
            while(!dq.empty() && (cols[i][j]-cols[dq.front().first-1][j] > d)){
                sum_window = (sum_window - dq.front().second + mod)%mod;
                dq.pop_front();
            }
            if(i>1){
                dq.push_back({i-1, dp[i-1][j]});
                sum_window = (sum_window + dp[i-1][j])%mod;
                dp[i][j] = (dp[i][j] + sum_window)%mod;
            }
        }
    }

    cout << dp[n][m]%mod << "\n";

    cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
