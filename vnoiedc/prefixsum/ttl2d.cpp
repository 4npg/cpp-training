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

#define maxn 1010
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, m, q;
long long pre[maxn][maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m>>q;

	f0(i, 1, n){
		f0(j, 1, m){
			long long x; cin>>x;
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + x;
		}
	}

	while(q--){
		int x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		x1--, y1--;
		cout<<pre[x2][y2] + pre[x1][y1] - pre[x1][y2] - pre[x2][y1]<<'\n';
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
