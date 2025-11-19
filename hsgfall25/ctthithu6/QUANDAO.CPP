// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define pii pair<int,int>
#define inf 1000000009
#define pb push_back
#define fi first 
#define se second 
int n,m;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);	
	cin>>n>>m;
	vector<int> h(n+1);

	f0(i,1,n)cin>>h[i];

	vector<vector<int>> a(n+1);
	vector<vector<int>> c(n+1);

	f0(i,0,m-1){
		int u,v;
		cin>>u>>v;
		int w = abs(h[u]-h[v]);
		a[u].pb(v); c[u].pb(w);
		a[v].pb(u); c[v].pb(w);
	}

	vector<int> d(n+1,inf);
	priority_queue<pii, vector<pii>,greater<pii>> pq;
	d[1] = 0;
	pq.push({0,1});
	while(!pq.empty()){
		auto top = pq.top();
		auto dc = top.fi;
		auto u = top.se;
		pq.pop();
		if(dc!=d[u])continue;
		if(u==n)break;
		for(size_t i=0;i<a[u].size();++i){
			int v = a[u][i];
			int w = c[u][i]; 
			int nd = max(dc,w);
			if(nd<d[v]){
				d[v] = nd;
				pq.push({nd,v});
			}
		}
	}

	cout<<d[n];

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


