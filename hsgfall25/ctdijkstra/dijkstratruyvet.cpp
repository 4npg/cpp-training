// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define pb push_back 


const int maxn = 2e5+18;
const int64 inf = 2e18;

int n,m;
vector< pair<int,int64> > a[maxn];
int pre[maxn];

void dijkstra(int s){
	vector<int64> d(n+1,inf);
	d[s] = 0;
	priority_queue< pair<int64,int>,vector< pair<int64,int>>, greater< pair<int64,int> >> Q;
	Q.push({0,s});

	while(!Q.empty()){
		auto top = Q.top(); Q.pop();
		int64 kc = top.fi;
		int u = top.second;

		if(kc>d[u])continue;
		for(auto it:a[u]){
			int v = it.fi;
			int64 w = it.se;
			if(d[v]>d[u]+w){
				d[v] = d[u] + w;
				pre[v] = u;
				Q.push({d[v],v});
			}
		}
	}
	if(d[n]==inf){
		cout<<-1;
		return ;
	}

	cout<<d[n]<<'\n';
	vector<int> path;
	for(int v=n;v!=0;v=pre[v])path.pb(v);
	reverse(all(path));
	cout<<(int)path.size()<<'\n';
	for(int x:path)cout<<x<<" ";
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	f0(i,0,m-1){
		int u,v;
		int64 w;
		cin>>u>>v>>w;
		a[u].pb({v,w});
		a[v].pb({u,w});
	}

	dijkstra(1);

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


