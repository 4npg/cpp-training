// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "cau2"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005
#define lg 20
#define inf (int64)4e18

int n;
int64 l, ans = -1;
int a[maxn], b[maxn];

bool check(int64 mid){
	int64 t = 0;
	f0(i, 0, n-1){
		if(a[i] < mid){
			t += (mid - a[i] + b[i] - 1)/b[i];
			if(t > l)return false;
		}
	}
	return t<=l;
}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	cin>>n>>l;
	f0(i, 0, n-1){
		cin>>a[i]>>b[i];
	}

	int64 lo = 1, hi = (int64)1e14;

	while(lo <= hi){
		int64 mid = lo + (hi-lo)/2;
		if(check(mid)){
			ans = mid;
			lo = mid + 1;
		}else hi = mid - 1;
	}

	cout<<ans;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
