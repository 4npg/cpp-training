// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define pb push_back
#define maxn 200012

int n,m;
vector<int> a[maxn];
int vis[maxn];
int cnt = 0;

void bfs(int s){
	++cnt;
	queue<int> q;
	q.push(s);
	vis[s] = true;
	while(!q.empty()){
		int u = q.front();q.pop();
		vis[u] = true;
		for(int v:a[u]){
			if(!vis[v]){
				vis[v] = true;
				q.push(v);
			}
		}
	}
}


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	f0(i,0,m-1){
		int u,v;
		cin>>u>>v;
		a[u].pb(v);
		a[v].pb(u);		
	}	
	memset(vis,0,n+1);
	f0(i,1,n){
		if(!vis[i])bfs(i);
	}
	cout<<cnt;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}





