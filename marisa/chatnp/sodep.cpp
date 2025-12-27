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

#define maxn (int64)1e18
#define lg 20
#define inf (int64)4e18

int k;
int64 l = 1, r = maxn;
int64 ans = -1;

bool check(int64 mid){
	return ((mid/3+mid/5+mid/7-mid/15-mid/21-mid/35+mid/105))>=k;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>k;

	while(l<r){
		int64 mid = l + (r-l)/2;

		if(check(mid)){
			r = mid;
		}else l = mid+1;
	}

	cout<<l;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
