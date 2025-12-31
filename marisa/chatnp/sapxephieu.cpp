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
long long k, a[maxn];

long long check(long long mid){
	long long cnt = 0;

	f0(i, 0, n-1){
		cnt += upper_bound(a + i + 1, a+n, a[i] + mid) - (a+i+1);
	}
	return cnt;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;
	f0(i, 0, n-1){
		cin>>a[i];
	}

	sort(a, a+n);

	long long l = 1, r = 1LL*1e9;

	while(l<=r){
		long long mid = l + (r-l)/2;
		if(check(mid) < k){
			l = mid + 1;
		}else r = mid - 1;
	}

	cout<<l;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
