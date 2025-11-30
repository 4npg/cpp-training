// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005
#define pb push_back

int n,q;
vector<int> g[maxn];

int in[maxn], out[maxn], sz[maxn], cnt, b[maxn], c[maxn], Euler[maxn];
int64 t[maxn*4];

/// c[u]: gia tri dinh u
/// Euler[i]: dinh thu i tren euler la dinh nao
/// b[i]: gia tri c cua dinh thuoc vi tri i tren euler tour
///  cnt la bien kiem soat chi so cua dinh thuoc euler tour

void update(int id, int l, int r, int p, int v){
	if(l == r)return void(t[id] = v);

	int mid = (l+r)/2;

	if(p<=mid)update(id*2, l, mid, p, v);
	else update(id*2+1, mid+1, r, p, v);

	t[id] = t[id*2] + t[id*2+1];
}

int64 get(int id, int l, int r, int u, int v){
	if(r<u||v<l)return 0;
	if(u<=l&&r<=v)return t[id];
	int mid = (l + r)/2;
	return get(id*2, l, mid, u, v) + get(id*2+1, mid+1, r, u, v);
}

void dfs(int u, int p){
	in[u] = ++cnt;
	Euler[cnt] = u;
	sz[u] = 1;
	b[cnt] = c[u];
	/// update(1, 1, n, cnt hoac in[u], c[u]);
	for(int v:g[u]){
		if(v!=p){
			dfs(v, u);
			sz[u] += sz[v];
		}
	}
	out[u] = cnt;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	f0(u,1,n)cin>>c[u];
	f0(i,1,n-1){
		int u,v;cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}	
	dfs(1, -1);
	f0(u,1,n){
		update(1, 1, n, in[u], c[u]);
	}

	while(q--){
		int type, u, v;
		cin>>type>>u;
		if(type==1){
			cin>>v;
			///c[u] = v;
			update(1, 1, n, in[u], v);
		}else {
			cout<< get(1, 1, n, in[u], out[u])<<'\n';
		}
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


