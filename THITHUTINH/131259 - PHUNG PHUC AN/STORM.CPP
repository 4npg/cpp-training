// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define file "STORM"
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define maxn 1010
#define fi first
#define se second

int n, m;
int a[maxn][maxn];
int sx, sy;
int cnt, cnt2;
bool vis[maxn][maxn];


int dx[] = {0, -1, 1, 0};
int dy[] = {-1, 0, 0, 1};

bool valid(int x, int y){
    return ((x>=1 && x<=n) && (y>=1 && y<=m));
}


void bfs(int sx, int sy){
    vis[sx][sy] = 1;
    cnt++;
    queue< pair<int, int> > q;
    q.push({sx, sy});

    while(!q.empty()){
        int x = q.front().fi;
        int y = q.front().se;
        q.pop();

        f0(i, 0, 3){
            int nx = x + dx[i];
            int ny = y + dy[i];

            if(valid(nx, ny) && !vis[nx][ny] && a[nx][ny] != 2){
                vis[nx][ny] = 1;
                cnt++;
                q.push({nx, ny});
            }
        }

    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen(file".inp","r",stdin);
    freopen(file".out","w",stdout);

    cin>>n>>m;
    f0(i, 1, n){
        f0(j, 1, m){
            cin>>a[i][j];
            if(a[i][j] == 0){
                sx = i;
                sy = j;
            }
            if(a[i][j] == 2)cnt2++;
        }
    }

    bfs(sx, sy);

    cout<<n*m - cnt2 - cnt;
    //cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
