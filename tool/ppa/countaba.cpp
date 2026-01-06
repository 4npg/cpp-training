// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "countaba"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 10004
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int n;
long long k, pre[maxn], cnt = 0;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>n>>k;
	map<long long, int> mp;
	mp[0] = 1;
	f0(i, 0, n-1){
		int x; cin>>x;
		pre[i+1] = pre[i] + x;
		if(mp.count(pre[i+1]-k)){
			cnt += mp[pre[i+1]-k];
		}

		mp[pre[i+1]]++;
	}

	cout<<cnt;

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
