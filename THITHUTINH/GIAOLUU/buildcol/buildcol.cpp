// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "buildcol"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 100005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n;
long long m, ma = -inf;
vector<long long> a;
long long pre[maxn], suf[maxn];

long long check(const vector<long long> &a, long long mid){
	int n = a.size();
	vector<long long> b(n);
	f0(i, 0, n-1) b[i] = max(a[i], mid);

	int l = 0, r = n-1;
	long long lma = 0, rma = 0, sum  = 0;

	while(l<=r){
		if(b[l] <= b[r]){
			lma = max(lma, b[l]);
			sum += max(0LL, lma - b[l]);
			++l;
		}else{
			rma = max(rma, b[r]);
			sum += max(0LL, rma - b[r]);
			r--;
		}
	}
	return sum;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	a.resize(n);
	f0(i, 0, n-1)cin>>a[i], ma = max(ma, a[i]);


	long long l = 0, r = 2LL*(1e9);
	long long ans = -1;

	while(l<=r){
		long long mid = l + (r-l)/2;
		if(check(a, mid)>=m){
			ans = mid; 
			l = mid + 1;
		}else r = mid - 1;
	}

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
