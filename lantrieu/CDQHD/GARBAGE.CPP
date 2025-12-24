// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "garbage"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1009

int m, n;
int64 a[maxn][maxn];
int64 dp[maxn][maxn];
int pre[maxn][maxn];

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>m>>n;
	f0(i, 1, m){
		f0(j, 1, n){
			cin>>a[i][j];
		}
	}

	f0(j, 1, n)dp[1][j] = a[1][j], pre[1][j] = j;

	f0(i, 2, m){
		f0(j, 1, n){
			int64 b = -1;
			int col = -1;
			f0(k, j-1, j+1){
				if(k<1 || k>n)continue;
				if(dp[i-1][k] > b){
					b = dp[i-1][k];
					col = k;
				}
			}
			dp[i][j] = a[i][j] + b;
			pre[i][j] = col;
		}
	}

	int64 res = -1;
	int lcol = -1;
	f0(j, 1, n){
		if(dp[m][j] > res){
			res = dp[m][j];
			lcol = j;
		}
	}

	vector<int> path(m+1);

	path[m] = lcol;

	fd(i, m, 2)path[i-1] = pre[i][path[i]];

	cout<<res<<'\n';
	cout<<path[1]<<'\n';
	f0(i, 2, m)cout<<path[i]<<'\n';

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
