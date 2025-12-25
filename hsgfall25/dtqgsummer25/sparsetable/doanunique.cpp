// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
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
#define lg 18
#define inf (int64)1e18
#define pb push_back 
#define fi first 
#define se second 

int n, q;
int64 a[maxn];
int L[maxn];
int64 f[maxn];

int64 t[lg][maxn];

int lg2(int n){
	return n ? 31 - __builtin_clz(n) : -1;
}

void init(){
	f0(i, 0, n-1)t[0][i] = f[i];

	f0(j, 1, lg){
		for(int i=1; i + (1<<j) <= n; i++){
			t[j][i] = max(t[j-1][i], t[j-1][i + (1<<(j-1))]);
		}
	}
}

int64 get(int l, int r){
	int k = lg2(r-l+1);
	return max(t[k][l], t[k][r-(1<<k)+1]);
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 0, n-1)cin>>a[i];

	unordered_map<int64, int> lst;
	int l = 0;
	f0(i, 0, n-1){
		if(lst.count(a[i]) && lst[a[i]] >= l){
			l = lst[a[i]] + 1;
		}

		L[i] = l;
		lst[a[i]] = i;
		f[i] = i - L[i] + 1;
	}

	init();

	while(q--){
		int u, v; cin>>u>>v;

		int lo = u, hi = v, pos = v + 1;

		while(lo <= hi){
			int mid = (lo + hi)/2;
			if(L[mid] >= u){
				pos = mid;
				hi = mid - 1;
			}else lo = mid + 1;
		}

		int64 ans = 0;

		if(pos > u){
			ans = max(ans, (int64)(pos-1-u+1));
		}

		if(pos <= v){
			ans = max(ans, get(pos, v));
		}
		cout<<ans<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
