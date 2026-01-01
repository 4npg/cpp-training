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

int n, k;
long long a[maxn];
vector<long long> dp(maxn);

struct seg{
	vector<long long> t;
	int n;

	seg(int N=0){
		n = N;
		if(n>0){
			t.assign(4*maxn, -inf);
		}
	}

	void build(int id, int l, int r, const vector<long long> &a){
		if(l == r){
			t[id] = a[l];
			return;
		}

		int mid = (l+r)/2;
		build(id*2, l, mid, a);
		build(id*2+1, mid+1, r, a);

		t[id] = max(t[id*2], t[id*2+1]);
	}

	void update(int id, int l, int r, int p, long long val){
		if(l == r){
			t[id] = val;
			return;
		}

		int mid = (l+r)/2;
		if(p<=mid)update(id*2, l, mid, p, val);
		else update(id*2+1, mid+1, r, p, val);

		t[id] = max(t[id*2], t[id*2+1]);
	}

	long long get(int id, int l, int r, int u, int v){
		if(v<l || r<u)return -inf;
		if(u<=l && r<=v)return t[id];

		int mid = (l+r)/2;
		long long tl = get(id*2, l, mid, u, v);
		long long tr = get(id*2+1, mid+1, r, u, v);

		return max(tl, tr);
	}

	void build(const vector<long long> &a){
		build(1, 1, n, a);
	}

	void update(int pos, long long val){
		update(1, 1, n, pos, val);
	}

	long long get(int l, int r){
		return get(1, 1, n, l, r);
	}
} sg;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;
	f0(i, 1, n)cin>>a[i];
	sg = seg(n);
	dp.assign(n+1, -inf);

	dp[n] = a[n];
	sg.update(n, dp[n]);
	fd(i, n-1, 1){
		if(i+k >= n){
			long long ma = sg.get(i+1, n);
			dp[i] = max(ma, 0LL) + 1LL*a[i];
			sg.update(i, dp[i]);
		}else{
			long long ma = sg.get(i+1, i+k);
			dp[i] = max(ma, 0LL) + a[i];
			sg.update(i, dp[i]);
		}
	}

	cout<<max(0LL, sg.get(1, n));
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
