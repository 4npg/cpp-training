// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "changest"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 101
#define pb push_back

string x, y;
int dp[maxn][maxn], pre[maxn][maxn];

struct Op {
    int type;
    int pos;
    char c;
};

youngboiz_nobug(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin>>x>>y;
    int n = x.size();
    int m = y.size();
    x = " " + x;
    y = " " + y;

    f0(i, 0, n){
    	dp[i][0] = i; 
    	pre[i][0] = 1; 
    }
    
    f0(j, 0, m){ 
    	dp[0][j] = j; 
    	pre[0][j] = 2; 
    }

    f0(i, 1, n){
        f0(j, 1, m){
            if(x[i] == y[j]){
                dp[i][j] = dp[i-1][j-1]; pre[i][j] = 0;
            } else {
                dp[i][j] = dp[i-1][j-1] + 1; pre[i][j] = 0;
            }
            if(dp[i-1][j] + 1 < dp[i][j]){
                dp[i][j] = dp[i-1][j] + 1; pre[i][j] = 1;
            }
            if(dp[i][j-1] + 1 < dp[i][j]){
                dp[i][j] = dp[i][j-1] + 1; pre[i][j] = 2;
            }
        }
    }

    int i = n, j = m;
    vector<Op> ops;
    while(i > 0 || j > 0){
        if(pre[i][j] == 0){
            if(x[i] != y[j]) ops.pb({0, i, y[j]});
            i--; j--;
        } else if(pre[i][j] == 1){
            ops.pb({1, i, 0}); 
            i--;
        } else {
            ops.pb({2, i+1, y[j]}); 
            j--;
        }
    }

    reverse(ops.begin(), ops.end());

    int del_cnt = 0, ins_cnt = 0;
    cout << ops.size() << '\n';
    for(auto &op: ops){
        if(op.type == 1){ 
            int idx = op.pos - del_cnt;
            cout << "D " << idx << '\n';
            del_cnt++;
        } else if(op.type == 2){ 
            int idx = op.pos - del_cnt + ins_cnt;
            cout << "I " << idx << " " << op.c << '\n';
            ins_cnt++;
        } else { 
            int idx = op.pos - del_cnt + ins_cnt;
            cout << "R " << idx << " " << op.c << '\n';
        }
    }
}
