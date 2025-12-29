// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "defense"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1003

int t;


youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	cin>>t;
	while(t--){
		int n; cin>>n;
		vector<int64> a(n+1, 0);
		vector<int> dp(n+1, 0);

		f0(i, 1, n)cin>>a[i];
		int ans = 0;
		dp[0] = 1;
		f0(i, 1, n){
			dp[i] = 1;
			f0(j, 1, i-1){
				if(a[i] > a[j]) dp[i] = max(dp[i], dp[j] + 1);
			}
			ans = max(ans, dp[i]);
		}

		cout<<ans<<'\n';
		a.clear();
		dp.clear();
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
