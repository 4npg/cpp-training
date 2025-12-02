// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define maxn 22

int n, m;
int a[maxn][maxn];
bool vis[maxn][maxn];

int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
int cnt;

bool nto(int n){
	if(n<2)return 0;
	if(n==2 || n==3)return 1;
	for(int i = 2; i*i<=n; ++i){
		if(n%i==0)return 0;
	}
	return 1;
}

void dfs(int x, int y){
	vis[x][y] = 1;
	a[x][y] = 0;
	for(int k = 0; k<=3; k++){
		int nx = x + dx[k];
		int ny = y + dy[k];
		if(!vis[nx][ny] && nto(a[nx][ny])){
			dfs(nx, ny);
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;		

	f0(i, 0, n-1){
		f0(j, 0, m-1){
			cin>>a[i][j];
		}
	}

	f0(i, 0, n-1){
		f0(j, 0, m-1){
			if(!vis[i][j] && nto(a[i][j])){
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout<<cnt<<'\n';
	f0(i, 0, n-1){
		f0(j, 0, m-1){
			cout<<a[i][j]<<" ";
		}
		cout<<'\n';
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





