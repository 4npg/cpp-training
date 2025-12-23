// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define pb push_back

int n, q;
int64 a[maxn], t[maxn*4], lazy[maxn*4];

void push(int id, int l, int r){
	if(lazy[id] == 0)return;

	t[id] += (r-l+1)*lazy[id];

	if(l!=r){
		lazy[id*2] += lazy[id];
		lazy[id*2+1] += lazy[id];
	}
	lazy[id] = 0;
}

void update(int id, int l, int r, int u, int v, int64 x){
	push(id, l, r);
	if(v<l || r<u)return ;

	if(u<=l && r<=v){
		lazy[id] += x;
		push(id, l, r);
		return ;
	}

	int mid = (l+r)/2;

	update(id*2, l, mid, u, v, x);
	update(id*2+1, mid+1, r, u, v, x);
	t[id] = t[id*2] + t[id*2+1];
}

int64 get(int id, int l, int r, int u, int v){
	push(id, l, r);
	if(v<l || r<u)return 0;
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;
	int64 tl = get(id*2, l, mid, u, v);
	int64 tr = get(id*2+1, mid+1, r, u, v);
	return tl + tr;
}
youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n){
		int64 x; cin>>x;
		update(1, 1, n, i, i, x);
	}

	while(q--){
		int type; cin>>type;
		if(type == 1){
			int u, v; int64 x;
			cin>>u>>v>>x;
			update(1, 1, n, u, v, x);
		}else{
			int u, v; cin>>u>>v;
			cout<<get(1, 1, n, u, v)<<'\n';
		}
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
