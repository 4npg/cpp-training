// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)


int n, q;
long long a[maxn];
long long t[maxn*4], lazy[maxn*4];

inline void push(int id, int l, int r){
	if(lazy[id] == 0)return;

	t[id] += lazy[id];

	if(l != r){
		lazy[id*2] += lazy[id];
		lazy[id*2+1] += lazy[id];
	}
	lazy[id] = 0;
}

void build(int id, int l, int r){
	if(l == r){
		t[id] = a[l];
		lazy[id] = 0;
		return ;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = max(t[id*2], t[id*2+1]);
}

void update(int id, int l, int r, int u, int v, long long val){
	push(id, l, r);

	if(v<l || r<u)return;
	if(u<=l && r<=v){
		lazy[id] += val;
		push(id, l, r);
		return;
	}

	int mid = (l+r)/2;
	update(id*2, l, mid, u, v, val);
	update(id*2+1, mid+1, r, u, v, val);

	t[id] = max(t[id*2], t[id*2+1]);
}

long long get(int id, int l, int r, int u, int v){
	push(id, l, r);

	if(v<l || r<u)return -inf;
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;

	long long tl = get(id*2, l, mid, u, v);
	long long tr = get(id*2+1, mid+1, r, u, v);

	return max(tl, tr);
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 1, n){
		cin>>a[i];
	}

	build(1, 1, n);

	cin>>q;
	while(q--){
		int type; cin>>type;
		if(type == 1){
			int x, y; cin>>x>>y;
			long long val; cin>>val;

			update(1, 1, n, x, y, val);
		}else{
			int l, r; cin>>l>>r;
			cout<<get(1, 1, n, l, r)<<'\n';
		}
	}

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
