// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define mod 100000007
#define maxn 1005
#define fi first
#define se second

int n,m;
string s[maxn];
int d[maxn][maxn];
int64 wa[maxn][maxn];

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("ant");
	cin>>n>>m;
	f0(i,1,n)cin>>s[i],s[i] = " " + s[i];

	memset(d,-1,sizeof d);

	queue< pair<int,int> > q;

	if(s[1][1] == '1'){
		q.push({1,1,});
		d[1][1] = 0;
		wa[1][1] = 1;
	}

	while(!q.empty()){
		auto top = q.front();
		q.pop();
		auto x = top.fi;
		auto y = top.se;
		for(int id=0;id<4;++id){
			int nx = x + dx[id];
			int ny = y + dy[id];
			if(nx<1 || nx>n || ny<1 || ny>m)continue;
			if(s[nx][ny] == '0')continue;

			if(d[nx][ny] == -1){
				d[nx][ny] = d[x][y] + 1;
				wa[nx][ny] = wa[x][y];
				q.push({nx,ny});	
			}else if(d[nx][ny] == d[x][y] + 1){
				wa[nx][ny] = (wa[nx][ny] + wa[x][y])%mod;
			}
		}
	}

	if(d[n][m] == -1)cout<<0<<'\n'<<0;
	else cout<< wa[n][m]%mod <<'\n'<<d[n][m];

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


