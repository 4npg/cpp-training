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
long long a[maxn][maxn];
long long pre[maxn][maxn];
long long ans = -inf;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>m>>n>>k;
	f0(i, 1, m){
		f0(j, 1, n){
			cin>>a[i][j];
		}
	}

	f0(i, 1, m){
		f0(j, 1, n){
			pre[i][j] = a[i][j] + pre[i-1][j] + pre[i-1][j-1] - pre[i-2][j-1];
			if(i>=k && j>=k){
				long long sum = pre[i][j] - pre[i-k][j] - pre[i-1][j-k] + pre[i-k-1][j-k];
				ans = max(ans , sum);
			}
		}
	}

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
