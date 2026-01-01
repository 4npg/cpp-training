// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n;
vector<int> v[maxn];
int dp[maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 0, n-1){
		int l, r; cin>>l>>r;
		v[r].emplace_back(l);
	}

	dp[0] = 0;

	f0(i, 1, maxn-1){
		dp[i] = dp[i-1];
		for(auto &j:v[i]){
			dp[i] = max(dp[i], dp[j-1] + i-j+1);
		}
	}

	cout<<dp[maxn-1];
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
