// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}
#define inf 1000000007
#define maxn 100005

int n,m;
int64 a[maxn];
int64 t[maxn*4], lazy[maxn*4];


void build(int id, int l, int r){
	if(l == r){
		t[id] = a[l];
		return;
	}

	int mid = l + ((r-l)>>1);
	build(2*id, l, mid);
	build(2*id+1, mid+1, r);
	t[id] = t[id*2]+ t[id*2+1];
}

void push(int id, int l, int r){
	if(!lazy[id])return;
	int mid = l + ((r-l)>>1);

	t[id*2] += lazy[id] * (mid-l+1);
	t[id*2+1] += lazy[id] * (r-mid);

	lazy[id*2] += lazy[id];
	lazy[id*2+1] += lazy[id];
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int64 val){
	if(r<u || v<l)return;

	if(u <= l && r <= v){
		t[id] += val * (r-l+1);
		lazy[id] += val;
		return ;
	}

	push(id, l, r);

	int mid = l + ((r-l)>>1);
	update(id*2, l, mid, u, v, val);
	update(id*2+1, mid+1, r, u, v, val);
	t[id] = t[id*2] + t[id*2+1];
}

int64 get(int id, int l, int r, int u, int v){
	if(v<l || r<u)return 0;

	if(l>=u && r<=v) return t[id];

	push(id, l, r);

	int mid = l + ((r-l)>>1);
	int64 get1 = get(2*id, l, mid, u, v);
	int64 get2 = get(2*id+1, mid+1, r, u, v);

	return get1+get2;
}

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>m;
	f0(i,1,n)cin>>a[i];

	build(1,1,n);

	while(m--){
		int tt;
		cin>>tt;
		if(tt==1){
			int l,r;
			int64 v;
			cin>>l>>r>>v;
			update(1,1,n,l,r,v);
		}else {
			int l,r;
			cin>>l>>r;
			cout<<get(1,1,n,l,r)<<'\n';
		}
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





