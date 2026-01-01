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

#define maxn 505
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, m;
char a[maxn][maxn];
bool vis[maxn][maxn];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, -1, 0, 1};

bool valid(int x, int y){
	return (x>=1 && x<=n && y>=1 && y<=m);
}

int cnt = 0;
bool khi; 

void dfs(int x, int y){
	vis[x][y] = 1;
	cnt++;
	f0(i, 0, 3){
		int nx = x + dx[i];
		int ny = y + dy[i];

		if(!valid(nx, ny))continue;

		if(a[nx][ny] == '.'){
			khi = true;
		}else if(a[nx][ny] == 'W' && !vis[nx][ny]){
			dfs(nx, ny);
		}
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;

	f0(i, 1, n){
		f0(j, 1, m){
			cin>>a[i][j];
		}
	}

	int res = 0;

	f0(i, 1, n){
		f0(j, 1, m){
			if(a[i][j] == 'W' && !vis[i][j]){
				cnt = 0;
				khi = false;
				dfs(i, j);

				if(!khi)res += cnt;
			}	
		}
	}

	cout<<res;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
