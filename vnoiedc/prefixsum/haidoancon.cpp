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

#define maxn 300005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n;

long long pre[maxn], suf[maxn], a[maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n; f0(i, 1, n)cin>>a[i];

	long long sum = a[1];
	pre[1] = a[1];

	f0(i, 2, n){
		sum = max(a[i], sum + a[i]);
		pre[i] = max(pre[i-1], sum);
	}

	sum = a[n];
	suf[n] = a[n];

	fd(i, n-1, 1){
		sum = max(a[i], sum + a[i]);
		suf[i] = max(suf[i+1], sum);
	}

	long long ans = -inf;

	f0(i, 1, n-1){
		ans = max(ans, pre[i] + suf[i+1]);
	}

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
