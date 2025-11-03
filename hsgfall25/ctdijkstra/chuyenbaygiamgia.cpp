// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back
#define fi first
#define se second


int n,m;
const int maxn = 2e5+5;
const int64 inf = 2e18;
vector< pair<int,int64> > a[maxn];
int64 d[maxn][2];

void dijkstra(){
	priority_queue<
		pair<int64,pair<int,int> >,
		vector< pair<int64,pair<int,int> > >,
		greater< pair<int64, pair<int,int> > >
	> q;

	f0(i,1,n){
		d[i][0] = d[i][1] = inf;
	}

	d[1][0] = 0;
	q.push({0,{1,0}});

	while(!q.empty()){
		auto top = q.top();q.pop();
		int64 du = top.fi;
		int u = top.se.fi;
		int used = top.se.se;
		if(du!=d[u][used])continue;

		for(auto x:a[u]){
			int v = x.fi;
			int64 w = x.se;
			if(d[v][used]>du+w){
				d[v][used] = du + w;
				q.push({d[v][used],{v,used}});
			}
			if(!used && d[v][1]>du+w/2){
				d[v][1] = du+w/2;
				q.push({d[v][1],{v,1}});
			}
		}
	}
	cout<<min(d[n][0],d[n][1]);

}


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f0(i,1,m){
		int u,v;
		int64 w;
		cin>>u>>v>>w;
		a[u].pb({v,w});
	}

	dijkstra();

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


