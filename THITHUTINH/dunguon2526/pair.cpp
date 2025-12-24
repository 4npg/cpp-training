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
#define inf (int64)4e18
#define lg 17 
#define mod (int64)1e9+7
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define fi first 
#define se second


int n, q;
int64 a[maxn];

struct node{
	int64 mi1, mi2;
};

note t[maxn*4];

node merge(node l, node r){
	vector<int64> v = {L.mi1, L.mi2, R.mi1, R.mi2};
	sort(all(v));
	return {v[0], v[1]};
}

void build(int id, int l, int r){
	if(l == r){
		t[id] = {a[l], inf};
		return;
	}

	int mid = (l + r)/2;
	build(id*2, l, mid);
	build(id*2+1, mid+1, r);

	t[id] = merge(t[id*2], t[id*2+1]);
}

void update(int id, int l, int r, int p, int64 x){
	if(l == r){
		t[id] = {x, inf};
		return;
	}

	int mid = (l + r)/2;
	if(p<=mid)update(id*2, l, mid, p, x);
	else update(id*2+1, mid+1, r, p, x);

	t[id] = merge(t[id*2], t[id*2+1]);
}

node get(int id, int l, int r, int u, int v){
	if(v<l || r<u)return {inf, inf};
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;
	node tl = get(id*2, l, mid, u, v);
	node tr = get(id*2+1, mid+1, r, u, v);

	return merge(tl, tr);
}

int64 mul(int64 a, int64 b){
	int64 ans = 0;
	while(b){
		if(b&1)ans = (ans+a)%mod;
		a = (a+a)%mod;
		b>>=1;
	}
	return ans;
}

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n)cin>>a[i];

	build(1, 1, n);

	while(q--){
		int type; cin>>type;
		if(type == 1){
			int p; int64 x;
			cin>>p>>x;
			update(1, 1, n, p, x);
		}else{
			int l, r; cin>>l>>r;
			node res = get(1, 1, n, l, r);
			
		}
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
