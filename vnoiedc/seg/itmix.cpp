// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

#define maxn 100000
#define inf (long long)4e18
#define mod (long long)(1e9+7)

struct Node{
	long long sum, add, mul, set;
};

Node st[4*maxn+5];
int n, m;

Node merge(Node a, Node b){
	return {(a.sum + b.sum) % mod, 0, 1, -1};
}

void apply_set(int id, long long v, int len){
	st[id].sum = v * len % mod;
	st[id].set = v;
	st[id].mul = 1;
	st[id].add = 0;
}

void apply_mul(int id, long long v, int len){
	st[id].sum = st[id].sum * v % mod;
	if(st[id].set != -1) st[id].set = st[id].set * v % mod;
	else st[id].mul = st[id].mul * v % mod;
	st[id].add = st[id].add * v % mod;
}

void apply_add(int id, long long v, int len){
	st[id].sum = (st[id].sum + v * len) % mod;
	if(st[id].set != -1) st[id].set = (st[id].set + v) % mod;
	else st[id].add = (st[id].add + v) % mod;
}

void push(int id, int l, int r){
	if(l == r) return;
	int mid = (l + r) >> 1;
	int lc = id<<1, rc = id<<1|1;

	if(st[id].set != -1){
		apply_set(lc, st[id].set, mid - l + 1);
		apply_set(rc, st[id].set, r - mid);
		st[id].set = -1;
	}
	if(st[id].mul != 1){
		apply_mul(lc, st[id].mul, mid - l + 1);
		apply_mul(rc, st[id].mul, r - mid);
		st[id].mul = 1;
	}
	if(st[id].add != 0){
		apply_add(lc, st[id].add, mid - l + 1);
		apply_add(rc, st[id].add, r - mid);
		st[id].add = 0;
	}
}

void build(int id, int l, int r){
	st[id] = {0, 0, 1, -1};
	if(l == r){
		long long x; cin >> x;
		st[id].sum = x % mod;
		return;
	}
	int mid = (l + r) >> 1;
	build(id<<1, l, mid);
	build(id<<1|1, mid+1, r);
	st[id] = merge(st[id<<1], st[id<<1|1]);
}

void upd_add(int id, int l, int r, int ql, int qr, long long v){
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr){
		apply_add(id, v, r - l + 1);
		return;
	}
	push(id, l, r);
	int mid = (l + r) >> 1;
	upd_add(id<<1, l, mid, ql, qr, v);
	upd_add(id<<1|1, mid+1, r, ql, qr, v);
	st[id] = merge(st[id<<1], st[id<<1|1]);
}

void upd_mul(int id, int l, int r, int ql, int qr, long long v){
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr){
		apply_mul(id, v, r - l + 1);
		return;
	}
	push(id, l, r);
	int mid = (l + r) >> 1;
	upd_mul(id<<1, l, mid, ql, qr, v);
	upd_mul(id<<1|1, mid+1, r, ql, qr, v);
	st[id] = merge(st[id<<1], st[id<<1|1]);
}

void upd_set(int id, int l, int r, int ql, int qr, long long v){
	if(qr < l || r < ql) return;
	if(ql <= l && r <= qr){
		apply_set(id, v, r - l + 1);
		return;
	}
	push(id, l, r);
	int mid = (l + r) >> 1;
	upd_set(id<<1, l, mid, ql, qr, v);
	upd_set(id<<1|1, mid+1, r, ql, qr, v);
	st[id] = merge(st[id<<1], st[id<<1|1]);
}

long long query(int id, int l, int r, int ql, int qr){
	if(qr < l || r < ql) return 0;
	if(ql <= l && r <= qr) return st[id].sum;
	push(id, l, r);
	int mid = (l + r) >> 1;
	return (query(id<<1, l, mid, ql, qr)
		  + query(id<<1|1, mid+1, r, ql, qr)) % mod;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n >> m;
	build(1, 1, n);

	while(m--){
		int type, l, r; long long x;
		cin >> type >> l >> r;
		if(type == 1){
			cin >> x;
			upd_add(1, 1, n, l, r, x % mod);
		}else if(type == 2){
			cin >> x;
			upd_mul(1, 1, n, l, r, x % mod);
		}else if(type == 3){
			cin >> x;
			upd_set(1, 1, n, l, r, x % mod);
		}else{
			cout << query(1, 1, n, l, r) << '\n';
		}
	}

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
