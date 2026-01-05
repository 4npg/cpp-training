// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "door"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod 998244353

int n;
long long s, a[maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>n>>s;
	f0(i, 0, n-1){
		cin>>a[i];
	}

	unordered_map<long long, long long> fq;

	fq[0] = 1;
	f0(i, 0, n-1){
		if(a[i] > s)continue;
		vector< pair<long long, long long> > tmp;

		for(auto &p:fq){
			long long nsum = p.first + a[i];
			if(nsum <= s)tmp.emplace_back(nsum, p.second);
		}

		for(auto &p:tmp){
			fq[p.first] = (fq[p.first] + p.second)%mod;
		}	
	}


	cout<<fq[s] % mod;

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
