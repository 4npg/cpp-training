// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
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
#define inf (int64)4e18

int n, k;
int64 a[maxn];
int64 l, r;

bool check(int64 x){
	int cnt = 1;
	int64 sum = 0;

	f0(i, 0, n-1){
		if(sum + a[i] <= x)sum+=a[i];
		else cnt++, sum = a[i];
	}

	return cnt<=k;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;
	f0(i, 0, n-1){
		cin>>a[i];
		l = max(l, a[i]);
		r += a[i];
	}

	while(l<r){
		int64 mid = l + (r-l)/2;

		if(check(mid))r = mid;
		else l = mid+1;
	}

	cout<<l;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
