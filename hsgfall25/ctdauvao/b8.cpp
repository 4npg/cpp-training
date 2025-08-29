// authur : anphung
// github : 4npg
#include <bits/stdc++.h>
using namespace std;
#define int64 long long
#define TASK "tenbai"
#define el cout<<"\n"
#define fast ios_base::sync_with_stdio(false); cin.tie(nullptr)
#define FOR(i,a,b) for(int (i)=(a);i<=(b);++i)
#define pb push_back

const int maxn = 1e5+5;
int n,m,q;
vector<int> a(maxn);
vector<vector<int>> g(maxn);
vector<bool> used(maxn,false);
vector<int> id(maxn);

struct TP{int sl=0; int64 tong=0; int max_vang=0;};
vector<TP> tp;

void dfs(int u,int comp_id){
	used[u]=true;
	id[u]=comp_id;
	tp[comp_id].sl++;
	tp[comp_id].tong+=a[u];
	tp[comp_id].max_vang=max(tp[comp_id].max_vang,a[u]);
	for(int v:g[u])
		if(!used[v])
			dfs(v,comp_id);
}

int32_t main(){
	fast;
	if(fopen(TASK".inp","r")){
		freopen(TASK".inp","r",stdin);
		freopen(TASK".out","w",stdout);
	}
	cin>>n>>m;
	FOR(i,1,n)cin>>a[i];
	FOR(i,1,m){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	int cnt=0;
	tp.pb(TP());
	FOR(i,1,n){
		if(!used[i]){
			tp.pb(TP());
			++cnt;
			dfs(i,cnt);
		}
	}
	cin>>q;
	while(q--){
		int x;
		cin>>x;
		int comp_id=id[x];
		cout<<tp[comp_id].sl<<" "<<tp[comp_id].tong<<" "<<tp[comp_id].max_vang;
		el;
	}
}
