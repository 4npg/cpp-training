// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n;
int64 a[maxn];
int64 pre[maxn];
int64 suf[maxn];
int64 sum;
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;

	f0(i, 0, n){
		pre[i] = LLONG_MIN;
		suf[i] = LLONG_MIN;
	}

	f0(i, 1, n){
		cin>>a[i];
		sum = max(a[i], sum+a[i]);
		pre[i] = max(pre[i-1], sum);
	}

	sum = 0;
	int64 ans = LLONG_MIN;

	fd(i, n, 1){
		sum = max(a[i], sum+a[i]);
		suf[i] = max(suf[i+1], sum);
	}

	f0(i, 1, n-1){
		ans = max(ans, pre[i] + suf[i+1]);
	}
	cout<<ans;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
