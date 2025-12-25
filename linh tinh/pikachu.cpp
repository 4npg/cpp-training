// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1009
#define inf 4e18
#define mod 1e9+7
#define lg 18

int n, m, q;
char a[maxn][maxn];

int dx[] = {};
int dy[] = {};

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m>>q;
	f0(i, 0, n-1){
		f0(j, 0, m-1){
			cin>>a[i][j];
		}
	}

	while(q--){
		int x, y, z, t;
		cin>>x>>y>>z>>t;
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
