// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "qua"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 500005
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

long long a[maxn], w[maxn], dp[maxn];
int n;

void sub1(){

	f0(i, 0, n-1)cin>>a[i]>>w[i];

	long long ans = 0;

	f0(i, 0, n-1){
		dp[i] = w[i];

		f0(j, 0, i-1){
			if(a[j] < a[i]){
				dp[i] = max(dp[i], dp[j] + w[i]);
			}
		}

		ans = max(ans, dp[i]);
	}

	cout<<ans;
}

long long t[maxn*4];

void update(int id, int l, int r, int p, long long x){
	if(l == r){
		t[id] = max(t[id], x);
		return;
	}

	int mid = (l+r)/2;
	if(p<=mid)update(id*2, l, mid, p, x);
	else update(id*2+1, mid+1, r, p, x);
	t[id] = max(t[id*2], t[id*2+1]);
}

long long get(int id, int l, int r, int u, int v){
	if(v<l || r<u)return 0;
	if(u<=l && r<=v)return t[id];

	int mid = (l+r)/2;

	long long tl = get(id*2, l, mid, u, v);
	long long tr = get(id*2+1, mid+1, r, u, v);

	return max(tl, tr);
}

void sub2(){
	vector<long long> b;

	f0(i, 0, n-1)cin>>a[i]>>w[i], b.emplace_back(a[i]);

	sort(b.begin(), b.end());

	b.erase(unique(b.begin(), b.end()), b.end());

	f0(i, 0, n-1){
		a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
	}

	int m = b.size();

	long long ans = 0;

	f0(i, 0, n-1){
		long long prv = (a[i] == 0 ? 0 : get(1, 1, m, 1, a[i]));
		long long dp = prv + w[i];
		update(1, 1, m, a[i]+1, dp);
		ans = max(ans, dp);
	}

	cout<<ans;
}
con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	cin>>n;
	if(n<=1003)sub1();
	else sub2();
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
