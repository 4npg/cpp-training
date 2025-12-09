// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 105
#define pb push_back
#define fi first 
#define se second
int n, m;
int a[maxn][maxn];
int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};
bool vis[maxn][maxn];
int cnt, ans, pos;
vector< pair<int, int> > cur;

bool valid(int x, int y){
	return (x>=1 && x<=n && y>=1 && y<=m);
}

void dfs(int x, int y){
    vis[x][y] = 1;
    cur.pb({x, y});
    f0(k, 0, 3){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(valid(nx, ny) && !vis[nx][ny] && a[nx][ny] > 0){
            dfs(nx, ny);
        }
    }
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
			if(!vis[i][j] && a[i][j] >0){
				dfs(i, j);
				int dt = 0;
				for(auto &p : cur){
				    int x = p.fi;
				    int y = p.se;
				    f0(k, 0, 3){
				        int nx = x + dx[k];
				        int ny = y + dy[k];
				        int ke = 0;
				        if(valid(nx, ny) && vis[nx][ny]){
				            ke = a[nx][ny];
				        }
				        dt += max(0, a[x][y] - ke);
				    }
				}
				cnt++;
				if(dt > ans){
				    ans = dt;
				    pos = cnt;
				}
				cur.clear();
			}
		}
	}

	cout<<cnt<<'\n'<<pos<<" "<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


