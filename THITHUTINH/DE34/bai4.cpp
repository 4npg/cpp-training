// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "bai4"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1004
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

vector<int> child[maxn];
int n;

int dp(int u){
	long long res = 1;
	long long prod = 1;

	for(auto &v:child[u]){
		prod = (prod*dp(v))%mod;
	}
	res = (res+prod)%mod;
	return res;
}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 1, n-1){
		int b; cin>>b;
		child[b].emplace_back(i);
	}

	long long ans = 1;
	for(auto &v:child[n]){
		ans = (ans * dp(v))%mod;
	}

	cout<<ans;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
