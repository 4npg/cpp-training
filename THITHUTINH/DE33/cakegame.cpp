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

int t;


con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long sum = 0;
		vector<long long> a(n, 0);
		f0(i, 0, n-1){
			cin>>a[i];
			sum += a[i];
		}
		int k = n/2 + 1;
		long long cur = 0;
		f0(i, 0, k-1){
			cur += a[i];
		}
		long long ans = cur;

		f0(i, k, n-1){
			cur += a[i] - a[i-k];
			if(cur < ans){
				ans = cur;
			}
		}
		cout<<ans<<" "<<sum - ans<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
