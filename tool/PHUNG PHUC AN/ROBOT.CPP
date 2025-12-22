// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "ROBOT"
#define pii pair<int, int> 
#define pli pair<int64, int64>

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1005
#define fi first 
#define se second 
#define pb push_back


int64 x1, y1, x2, y2;
int64 d[maxn][maxn];
bool vis[maxn][maxn];

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

void sub1(){
	int b = 4;
	int64 lx = min(x1, x2) - b*1ll;
	int64 rx = max(x1, x2) + b*1ll;
	int64 ly = min(y1, y2) - b*1ll;
	int64 ry = max(y1, y2) + b*1ll;

	map<pli, int64> d;
	queue<pli> q;
	q.push({x1, y1});	
	d[{x1, y1}] = 0;

	while(!q.empty()){
		auto top = q.front(); q.pop();
		int64 x = top.fi;
		int64 y = top.se;

		if(x == x2 && y == y2){
			cout<<d[{x, y}];
			return ;
		}

		f0(i, 0, 7){
			int64 nx = x + dx[i];
			int64 ny = y + dy[i];

			if(nx < lx || nx > rx || ny < ly || ny > ry)continue;
			if(d.count({nx, ny})) continue;

			d[{nx, ny}] = d[{x, y}] + 1;
			q.push({nx, ny});
		}
	}
}

void sub2(){
	int64 dx = llabs(x2 - x1);
	int64 dy = llabs(y2 - y1);
	cout<<max(dx, dy);
}

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>x1>>y1>>x2>>y2;

	sub2();
	
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
