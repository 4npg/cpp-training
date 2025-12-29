// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "bulls"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define mod 2114992

int n, k;
int64 dp[maxn];

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);
	
	cin>>n>>k;

	dp[0] = 1;
	int64 res = 0;

	f0(x, 0, n){
		if(x + k*(x-1) > n)break;

		int64 ttp = n - k*(x-1);
		dp[0] = 1;
		f0(i, 1, x){
			dp[i] = (dp[i-1] * (ttp - i + 1)/i);
		}
		res += dp[x];
	}
	
	cout<<res%mod;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
