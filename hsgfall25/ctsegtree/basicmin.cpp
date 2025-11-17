// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005
#define inf (int64)2e18
int n,q;
int a[maxn];
int64 t[maxn*4];
void build (int id, int l, int r){
	if(l==r){
		t[id]=a[l];
		return;
	}
	int mid = (l+r)/2;
	build(id*2,l,mid);
	build(id*2+1,mid+1,r);
	t[id] = min(t[id*2], t[id*2+1]);
}

int64 get(int id, int l, int r, int u, int v){
	if(r<u||v<l)return inf;
	if(u<=l&&r<=v)return t[id];
	int mid = (l+r)/2;
	int64 tl = get(id*2, l, mid, u, v);
	int64 tr = get(id*2+1, mid+1, r, u, v);
	return min(tl,tr);
}

void update(int id, int l, int r, int pos, int x){
	if(l==r){
		t[id] = a[pos] = x;
		return ;
	}
	int mid = (l+r)/2;
	if(pos<=mid)update(id*2, l, mid, pos, x);
	else update(id*2+1, mid+1, r, pos, x);
	t[id] = min(t[id*2] , t[id*2+1]);
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	f0(i,1,n)cin>>a[i];
	build(1,1,n);
	while(q--){
		int t,u,v;cin>>t>>u>>v;
		if(t==1){
			update(1,1,n,u,v);
		}else cout<<get(1,1,n,u,v)<<'\n';
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


