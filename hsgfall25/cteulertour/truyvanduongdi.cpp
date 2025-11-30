// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005

vector<int> a[maxn];
int64 lazy[maxn*4];
int64 t[maxn*4];

void dfs(int u, int p){
	in[u] = ++cnt;
	for(int v:a[u]){
		if(v!=p){
			dfs(v);
		}
	}
	out[u] = cnt;
}

void update(int id, int l, int r, int p, int v){
	if(l==r)return void(t[id] = v);

	int mid = (l+r)/2;
	if(p<=mid)update(id*2, l, mid+1, p, v);
	else update(id*2+1, mid+1, r, p, v);
	t[id] = t[id*2] + t[id*2+1];
}

int64 

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
		
	f0(u,1,n){
		update(1, 1, n, in[u], out[u], c[v]);
	}

	while(q--){
		int type, u, v;
		cin>>type;
		if(type==1){
			update(1,1,n,in[u], out[u], -c[u] + v);
			c[u] = v;
		}
		else{
			cout<<get()
		}
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


