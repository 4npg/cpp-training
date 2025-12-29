// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "caykhe"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 129
#define pb push_back

int n, m;
int a[maxn], b[maxn];
int dp[maxn][maxn];
vector<int> tr;

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	cin>>n>>m;
	f0(i, 1, n)cin>>a[i]>>b[i];

	dp[0][0] = 0;

	f0(i, 1, n){
		fd(j, m, b[i]){
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-b[i]] + a[i]);
		}
	}

	cout<<dp[n][m]<<'\n';

	int j = m;
	fd(i, n, 1){
		if(dp[i][j] != dp[i-1][j]){
			tr.pb(i);
			j -= b[i];
		}
	}

	sort(tr.begin(), tr.end());
	cout<<tr.size()<<" ";
	for(auto &x:tr)cout<<x<<" ";

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
