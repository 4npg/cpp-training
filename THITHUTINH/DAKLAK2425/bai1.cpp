// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "bai1"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

long long n;
long long ans = -1;
long long check(long long mid){
	return (mid*(mid+1)*(2*mid+1))/6;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	long long l = 1, r = 2e6;
	while(l<=r){
		long long mid = l + (r-l)/2;
		if(check(mid)<=n){
			ans = mid;
			l = mid + 1;
		}else r = mid - 1;
	}

	cout<<ans<<'\n'<<n - check(ans);
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
