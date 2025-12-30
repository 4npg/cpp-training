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
double a[maxn];
double l = 1, r = 1000000009;
double ans;

bool check(double mid){
	vector<double> pre(n+1, 0.0);

	f0(i, 0, n-1){
		pre[i+1] = pre[i] + a[i] - mid;
	}

	double mi = 0.0;
	f0(i, k, n){
		mi = min(mi, pre[i-k]);
		if(pre[i] - mi >= 0)return true;
	}
	return false;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;
	f0(i, 0, n-1){
		cin>>a[i];
	}

	f0(i, 1, 60){
		double mid = (l+r)/2.0;
		if(check(mid)){
			ans = mid; l = mid;
		}else r = mid;
	}

	cout<<fixed<<setprecision(3)<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
