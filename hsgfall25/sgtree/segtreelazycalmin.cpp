// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005
#define inf 1e9

int n,q;
int64 a[maxn], t[maxn*4], lazy[maxn*4];

void build(int id, int l, int r){
	if(l == r){
		t[id] = a[l];
		return;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = min(t[id*2], t[id*2+1]);
}

void push(int id){

	lazy[id*2] += lazy[id];
	t[id*2] += lazy[id];

	lazy[id*2+1] += lazy[id];
	t[id*2+1] += lazy[id];

	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int64 x){
	if(v<l || r<u)return;
	if(u<=l && r<=v){
		t[id] += x;
		lazy[id] += x;
		return;
	}

	int mid = (l+r)/2;
	push(id);

	update(id*2, l, mid, u, v, x);
	update(id*2+1, mid+1, r, u, v, x);

	t[id] = min(t[id*2], t[id*2+1]);
}


int64 get(int id, int l, int r, int u, int v){
	if(v<l || r<u)return inf;
	if(u<=l && r<=v){
		return t[id];
	}

	int mid = (l+r)/2;
	push(id);
	int64 tl = get(id*2, l, mid, u, v);
	int64 tr = get(id*2+1, mid+1, r, u, v);

	return min(tl, tr);
}
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	f0(i, 1, n)cin>>a[i];

	build(1, 1, n);

	while(q--){
		int t, l, r;
		cin>>t>>l>>r;
		if(t==1){
			int64 x; cin>>x;
			update(1, 1, n, l, r, x);
		}else cout<<get(1, 1, n, l, r)<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


