// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back

int n,k,m;
const int maxn = 1e5+5;
vector<int> a[maxn];
int dist[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	vector<int> exits(k);
	f0(i,0,k-1)cin>>exits[i];
	cin>>m;
	f0(i,1,m){
		int u,v;cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);
	}
	memset(dist,-1,sizeof(dist));
	queue<int> q;
	for(int x:exits){
		dist[x] = 0;
		q.push(x);
	}
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int v:a[u])if(dist[v]==-1){
			dist[v] = dist[u]+1;
			q.push(v);
		}
	}
	f0(i,1,n)cout<<dist[i]<<" ";
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


