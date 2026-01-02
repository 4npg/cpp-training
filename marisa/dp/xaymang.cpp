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

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, k;
bool d[maxn];
vector<int> nto;
long long dp[105][1005];

void sang(){
	for(int i=2; i*i<maxn; i++){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}

	f0(i, 2, maxn-1)if(!d[i])nto.emplace_back(i);
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;

	sang();

	f0(i, 0, k)dp[1][i] = 1;

	f0(i, 2, n){
		f0(j, 0, k){
			for(int &x:nto){
				if(x>=j && x-j<=k)dp[i][j] = (dp[i][j]%mod + dp[i-1][x-j]%mod)%mod;
			}
		}
	}

	long long ans = 0;
	f0(j, 0, k)ans = (ans%mod + dp[n][j]%mod)%mod;

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
