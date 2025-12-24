// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "STEP"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1009
#define mod 13051984

int n, k;
int dp[maxn];

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;
	unordered_set<int> hong;

	f0(i, 0, k-1){
		int x; cin>>x;
		hong.insert(x);
	}

	dp[0] = 1;
	dp[1] = (hong.count(1)?0:1);

	f0(i, 2, n){
		if(hong.count(i))dp[i] = 0;
		else dp[i] = (dp[i-1] + dp[i-2])%mod;
	}

	cout<<dp[n]%mod;
	
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
