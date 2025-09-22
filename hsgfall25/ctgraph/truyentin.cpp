// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back

int n,m;
const int maxn = 2e5+5;
vector<int> a[maxn];
int dist[maxn];


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	f0(i,0,m-1){
		int u,v;cin>>u>>v;
		a[u].pb(v);a[v].pb(u);
	}	

	memset(dist,-1,sizeof(dist));
	queue<int> que;
	que.push(1);
	dist[1] = 0;

	while(!que.empty()){
		int u = que.front();que.pop();
		for(int v:a[u]){
			if(dist[v]==-1){
				dist[v] = dist[u]+1;
				que.push(v);
			}
		}
	}
	if(dist[n]==-1)cout<<-1;
	else cout<<dist[n]+1;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


