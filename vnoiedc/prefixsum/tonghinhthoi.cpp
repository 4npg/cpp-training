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

#define maxn 1005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, k;
long long P[maxn][maxn];
long long pre[maxn][maxn];

long long get(int u1, int v1, int u2, int v2, int U, int V){
	u1 = max(1, u1);
	u2 = min(U-1, u2);
	v1 = max(1, v1);
	v2 = min(V-1, v2);

	if(u1 > u2 || v1 > v2)return 0LL;
	return pre[u2][v2] - pre[u1-1][v2] - pre[u2][v1-1] + pre[u1-1][v1-1];
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;

	f0(i, 1, n){
		f0(j, 1, n){
			cin>>P[i][j];
		}
	}

	int U=2*n+2;
	int dich = n+2;
	int V = 2*n+5;

	vector<vector<long long>> B(U, vector<long long>(V, 0));

	f0(x, 1, n){
		f0(y, 1, n){
			int u = x + y;
			int v = x - y + dich;
			B[u][v] += P[x][y];
		}
	}

	f0(i, 1, U-1){
		f0(j, 1, V-1){
			pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + B[i][j];
		}
	}

	long long ans = 0;

	f0(i, 1, n){
		f0(j, 1, n){
			int u0 = i+j;
			int v0 = i-j+dich;

			ans = max(ans, get(u0-k, v0-k, u0+k, v0+k, U, V));
		}
	}

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
