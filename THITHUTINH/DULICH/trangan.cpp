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

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n, m;
int a[maxn];
int ans = 1;
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>m>>n;
	int sz = 0;
	f0(i, 0, n-1){
		int x; cin>>x;
		if(x != 0)a[sz++] = x;
	}

	sort(a, a+sz);

	int l = 0;

	f0(r, 0, sz-1){
		while(a[r] - a[l] + 1 - (r-l+1) > 1){
			l++;
		}
		ans = max(ans, r-l+2);
	}

	cout<<min(ans, m);
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
