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
const int maxn = 1e5+5;
const int64 inf = 2e18;
const int mod = 1e9+7;
vector< pair<int,int> > a[maxn];
int64 d[maxn];
int64 cnt[maxn];
int minEdge[maxn],maxEdge[maxn];

void dijkstra(){
	priority_queue<
		pair<int64,int>,
		vector< pair<int64,int> >,
		greater< pair<int64,int> >
	> q;

	f0(i,1,n){
		d[i] = inf;
		cnt[i] = 0;
		minEdge[i] = 1e9;
		maxEdge[i] = -1e9;
	}

	d[1] = 0;
	cnt[1] = 1;
	minEdge[1] = maxEdge[1] = 0;
	q.push({0,1});

	while(!q.empty()){
		auto top = q.top();q.pop();
		int64 du = top.fi;
		int u = top.se;
		if(du!=d[u])continue;
		for(auto x:a[u]){
			int v = x.fi;
			int w = x.se;
			if(d[v]>du+w){
				d[v] = du+w;
				cnt[v] = cnt[u];
				minEdge[v] = minEdge[u]+1;
				maxEdge[v] = maxEdge[u]+1;
				q.push({d[v],v});
			}else if(d[v]==du+w){
				cnt[v] = (cnt[v]+cnt[u])%mod;
				minEdge[v] = min(minEdge[v],minEdge[u]+1);
				maxEdge[v] = max(maxEdge[v],maxEdge[u]+1);
			}
		}
	}
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	f0(i,1,m){
		int u,v,w;
		cin>>u>>v>>w;
		a[u].pb({v,w});
	}

	dijkstra();
	cout<<d[n]<<" "<<cnt[n]<<" "<<minEdge[n]<<" "<<maxEdge[n];

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


