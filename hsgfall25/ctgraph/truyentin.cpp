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
int d[maxn];


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>m;
	f0(i,0,m-1){
		int u,v;cin>>u>>v;
		a[u].pb(v);a[v].pb(u);
	}	

	memset(d,-1,sizeof(d));
	queue<int> que;
	que.push(1);
	d[1] = 0;

	while(!que.empty()){
		int u = que.front();que.pop();
		// for(auto &x:a[u])cout<<x<<" ";
		// cout<<'\n';
		for(int v:a[u]){
			if(d[v]==-1){
				d[v] = d[u]+1;
				//cout<<u<<" "<<d[u]<<" : "<<v<<" "<<d[v]<<'\n';
				que.push(v);
			}
		}
	}
	//cout<<"res = "<<" : ";
	if(d[n]==-1)cout<<-1;
	else cout<<d[n]+1;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


