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

int n, m;
long long a[maxn];

multiset<long long> t[maxn*4];

void build(int id, int l, int r){
	if(l == r){
		t[id].insert(a[l]);
		return;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = t[id*2+1];
	for(auto &x:t[id*2])t[id].insert(x);
}

void update(int id, int l, int r, int i, long long old, long long val){
	if(l>i || r<i)return;
	if(l == r){
		t[id].clear();
		t[id].insert(val);
		return;
	}

	int mid = (l+r)/2;
	update(id*2, l, mid, i, old, val);
	update(id*2+1, mid+1, r, i, old, val);

	t[id].erase(t[id].find(old));
	t[id].insert(val);

}

long long get(int id, int l, int r, int u, int v, int k){
	if(v<l || r<u)return inf;
	if(u<=l && r<=v){
		auto it = t[id].lower_bound(k);
		if(it == t[id].end())return inf;
		return *it;
	}

	int mid = (l+r)/2;
	long long tl = get(id*2, l, mid, u, v, k);
	long long tr = get(id*2+1, mid+1, r, u, v, k);

	return min(tl, tr);
}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	f0(i, 1, n)cin>>a[i];
	build(1, 1, n);
	while(m--){
		int type; cin>>type;
		if(type == 1){
			int i; cin>>i;
			long long v; cin>>v;
			update(1, 1, n, i, a[i], v);
			a[i] = v;
		}else{
			int l, r; cin>>l>>r;
			long long k; cin>>k;
			long long ans = get(1, 1, n, l, r, k);
			cout<<((ans == inf)?-1:ans)<<'\n';
		}
	}
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
