// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005
#define pb push_back

int n,m;
vector<int> a[maxn],rev[maxn];
int d1[maxn],d2[maxn];

void bfs(int s,vector<int> g[],int d[]){
	queue<int> q;
	f0(i,1,n)d[i] = -1;
	d[s] = 0;
	q.push(s);
	while(!q.empty()){
		int u = q.front();q.pop();
		for(int v:g[u]){
			if(d[v] == -1){
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
	}
}


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;
	f0(i,1,m){
		int u,v;
		cin>>u>>v;
		a[u].pb(v);
		rev[v].pb(u);
	}

	bfs(1,a,d1);
	bfs(1,rev,d2);

	int ans = INT_MAX;

	f0(u,1,n){
		for(int v:a[u]){
			if(d1[u]!=-1&&d2[v]!=-1){
				ans = min(ans,d1[u] + d2[v] + 1);
			}
		}
	}

	if(ans == INT_MAX)cout<<-1;
	else cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


