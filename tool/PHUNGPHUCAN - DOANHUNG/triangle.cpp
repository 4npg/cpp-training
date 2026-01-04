// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "triangle"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 2005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, m, k;
int a[maxn][maxn];
long long r[maxn][maxn], c[maxn][maxn], cheo[maxn][maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>n>>m>>k;
	f0(i, 1, n){
		f0(j, 1, m){
			cin>>a[i][j];
		}
	}

	f0(i, 1, n){
		f0(j, 1, m){
			r[i][j] = r[i][j-1] + a[i][j];
		}
	}

	f0(j, 1, m){
		f0(i, 1, n){
			c[i][j] = c[i-1][j] + r[i][j];
		}
	}

	f0(i, 1, n){
		f0(j, 1 ,m){
			cheo[i][j] = cheo[i-1][j-1] + r[i][j];
		}
	}

	long long ans = -inf;

	for(int i=1; i+k-1<=n; ++i){
		for(int j=1; j+k-1<=m; j++){
			int x = i+k-1;
			int y = j+k-1;

			ans = max(ans, cheo[x][y] - cheo[i-1][j-1] - (c[x][j-1] -c[i-1][j-1]));
		}
	}

	cout<<ans;

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
