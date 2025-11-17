// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define inf (int64)1e18
#define maxn 200005

int n,q;
int64 a[maxn+100];
int64 t[maxn*4+4], lazy[maxn*4+4];
void build(int id, int l, int r){
	if(l==r){
		t[id] = a[l];
	}else{
		int mid = (l + r)/2;
		build(id*2, l, mid);
		build(id*2+1, mid+1, r);
		t[id] = min(t[id*2], t[id*2+1]);
	}
}

void push(int id){
	t[id*2] += lazy[id];
	lazy[id*2] += lazy[id];
	t[id*2+1] += lazy[id];
	lazy[id*2+1] += lazy[id];
	lazy[id] = 0;
}

void update(int id, int tl,int tr, int l, int r, int64 add){
	if(l>r)return;
	if(l==tl&&r==tr){
		t[id] += add;
		lazy[id] += add;
	}else{
		push(id);
		int tm = (tl+tr)/2;
		update(id*2, tl, tm, l, min(r, tm), add);
		update(id*2+1, tm+1, tr, max(l, tm+1), r, add);
		t[id] = min(t[id*2], t[id*2+1]);
	}
}

int64 query(int id, int tl, int tr, int l, int r){
	if(l>r)return inf;
	if(l<=tl && tr <= r) return t[id];
	push(id);
	int tm = (tl + tr)/2;
	return min(
		query(id*2, tl, tm, l, min(r,tm)),
		query(id*2+1, tm+1, tr, max(l, tm+1), r)
	);
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>q;
	f0(i,1,n)cin>>a[i];
	build(1,1,n);

	while(q--){
		int t;cin>>t;
		int l,r;cin>>l>>r;
		if(t==1){
			int64 x;cin>>x;
			update(1,1,n,l,r,x);
		}else{
			cout<<query(1,1,n,l,r)<<'\n';
		}
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


