// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pb push_back
#define fi first
#define se second 
#define maxn 1005

int n, m;
char a[maxn][maxn];
bool vis[maxn][maxn];
int cnt;
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
vector< pair<int, int> > cur;
int soi, cuu;

bool valid(int x, int y){
	return ((x>=1 && x<=n && y>=1 && y<=m));
}
pair<int,int> dfs(int x, int y){
    vis[x][y] = 1;
    int csoi = 0, ccuu = 0;

    if(a[x][y] == 'v') csoi++;
    else if(a[x][y] == 'o') ccuu++;

    f0(k, 0, 3){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(valid(nx,ny) && !vis[nx][ny] && a[nx][ny] != '#'){
            auto nt = dfs(nx,ny);
            csoi += nt.fi;
            ccuu += nt.se;
        }
    }

    return {csoi, ccuu};
}

pair<int, int> bfs(int ngx, int ngy){
	vis[ngx][ngy] = 1;
	int csoi = 0, ccuu = 0;
	if(a[ngx][ngy] == 'v')csoi++;
	else if(a[ngx][ngy] == 'o')ccuu++;
	queue< pair<int, int> > q;
	q.push({ngx, ngy});

	while(q.size()){
		auto top = q.front();
		int x = top.fi, y = top.se;
		q.pop();

		f0(i, 0, 3){
			int nx = x + dx[i];
			int ny = y + dy[i];
			if(valid(nx,ny) && !vis[nx][ny] && a[nx][ny] != '#'){
				vis[nx][ny] = 1;
				if(a[nx][ny] == 'v')csoi++;
				else if(a[nx][ny]=='o')ccuu++;
				q.push({nx, ny});
			}
		}
	}
	return {csoi, ccuu};
}
int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	f0(i, 1, n){
		f0(j, 1, m){
			cin>>a[i][j];
		}
	}	
	f0(i, 1, n){
		f0(j, 1, m){
			if(!vis[i][j] && a[i][j] != '#'){
				auto q = bfs(i, j);
				if(q.se > q.fi)q.fi = 0;
				else q.se = 0;
				cuu += q.se;
				soi += q.fi;
			}
		}
	}

	cout<<cuu<<" "<<soi;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


