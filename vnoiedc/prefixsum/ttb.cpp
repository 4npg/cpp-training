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

int n; 
vector<int> a;
int k;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>k;
	a.resize(n);
	f0(i, 0, n-1){
		cin>>a[i]; 
		a[i]-=k;
	}

	map<long long, int> mp;
	long long sum = 0;
	long long cnt = 0;
	mp[0] = 1;
	for(auto &x:a){
		sum += x;
		if(mp.count(sum)){
			cnt += mp[sum];
		}
		mp[sum]++;
	}

	cout<<cnt;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
