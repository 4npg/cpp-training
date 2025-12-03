// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define mod (int64)1e9+7
#define maxn 100005

int n, m;
int64 t[maxn*4], lazy[maxn*4];

int64 mul(int64 a, int64 b){
	int64 ans = 0;
	while(b){
		if(b&1)ans = (ans+a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
}

void build(int id, int l, int r){
	lazy[id] = 1;
	if(l == r){
		t[id] = 1;
		return ;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = t[id*2] + t[id*2+1];
}

void push(int id){
	lazy[id*2] *= lazy[id];
	t[id*2] *= lazy[id];

	lazy[id*2+1] *= lazy[id];
	t[id*2+1] *= lazy[id];

	lazy[id] = 1;
}

void update(int id, int l, int r, int u, int v, int64 x){
	if(v<l || r<u)return ;
	if(u<=l && r<=v){
		t[id] *= x;
		lazy[id] *= x;
		return;
	}

	int mid = (l+r)/2;
	push(id);

	update(id*2, l, mid, u, v, x);
	update(id*2+1, mid+1, r, u, v, x);

	t[id] = t[id*2] + t[id*2+1];
}

int64 get(int id, int l, int r, int u, int v){
	if(v<l || r<u)return 0;
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;
	push(id);

	int64 tl = get(id*2, l, mid, u, v);
	int64 tr = get(id*2+1, mid+1, r, u, v);

	return tl + tr;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>m;

	build(1, 1, n);

	while(m--){
		int type, l, r;
		cin>>type>>l>>r;
		if(type == 1){
			int64 v; cin>>v;
			update(1, 1, n, l, r, v);
		}else cout<<get(1, 1, n, l, r)<<'\n';
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


