// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int q, n;

vector<long long> t[maxn], a;
inline vector<long long> merge(vector<long long> &a, vector<long long> &b){
	int i = 0, j = 0;
	vector<long long> c;

	while(i<a.size() && j<b.size()){
		if(a[i] > b[j]){
			c.emplace_back(b[j++]);
		}else{
			c.emplace_back(a[i++]);
		}
	}

	while(i<a.size()){
		c.emplace_back(a[i++]);
	}

	while(j<b.size()){
		c.emplace_back(b[j++]);
	}

	return c;
}

void build(int id, int l, int r){
	if(l == r){
		t[id] = {a[l]};
		return;
	}

	int mid = (l+r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = merge(t[id*2], t[id*2+1]);
}

long long get(int id, int l, int r, int u, int v, long long k){
	if(v<l || r<u)return 0;
	if(u<=l && r<=v)return t[id].end() - upper_bound(t[id].begin(), t[id].end(), k);

	int mid = (l+r)/2;
	long long tl = get(id*2, l, mid, u, v, k);
	long long tr = get(id*2+1, mid+1, r, u, v, k);

	return tl + tr;
}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n; a.resize(n);
	
	cin>>q;
	for(long long &x:a)cin>>x;

	build(1, 0, n-1);

	while(q--){
		int i, j;
		long long k;
		 cin>>i>>j>>k;
		cout<<get(1, 0, n-1, i-1, j-1, k)<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
