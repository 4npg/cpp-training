// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int n,m;
const int maxn = 1e3+5;
char a[maxn][maxn];
bool vis[maxn][maxn];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

void dfs(int x,int y){
	vis[x][y] = true;
	f0(k,0,3){
		int nx = x+dx[k];
		int ny = y+dy[k];
		if(nx>=0&&nx<n&&ny>=0&&ny<m){
			if(!vis[nx][ny]&&a[nx][ny]=='.'){
				dfs(nx,ny);
			}
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	f0(i,0,n-1){
		f0(j,0,m-1){
			cin>>a[i][j];
		}
	}

	int ans = 0;
	f0(i,0,n-1){
		f0(j,0,m-1){
			if(a[i][j] =='.' && !vis[i][j]){
				dfs(i,j);
				ans++;
			}
		}
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


