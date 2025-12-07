// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pli pair<int64, int>, vector<pair<int64, int>>
#define maxn 200005
#define fi first 
#define se second
#define pb push_back
#define inf (int64)1e15

int n, m;
vector< pair<int64, int>> a[maxn];
int64 d[maxn];
int pre[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;

	f0(i, 1, m){
		int u, v;
		int64 w;
		cin>>u>>v>>w;
		a[u].pb({v, w});
		a[v].pb({u, w});
	}	

	f0(u, 1, n)d[u] = inf;
	d[1] = 0;

	priority_queue<pli> q;
	q.push({-d[1], 1});

	while(q.size()){
		int64 du = -q.top().fi;
		int u = q.top().se;
		q.pop();

		if(du != d[u])continue;
		for(auto &p:a[u]){
			int v = p.fi;
			int64 w = p.se;
			if(d[u] + w < d[v]){
				d[v] = d[u] + w;
				pre[v] = u;
				q.push({-d[v], v});
			}
		}
	}

	if(d[n] == inf){
		cout<<-1;
		return 0;
	}

	cout<<d[n]<<'\n';
	vector<int> path;
	for(int v = n; v!=0; v=pre[v])path.pb(v);
	reverse(path.begin(), path.end());
	for(auto &x:path)cout<<x<<" ";
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


