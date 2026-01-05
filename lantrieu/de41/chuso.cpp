// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "chuso"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

int k, m, n;

long long opw(long long a, long long b, long long mul){
	long long ans = 1;
	while(b){
		if(b&1)ans = (ans*a)%mul;
		a = (a*a)%mul;
		b>>=1;
	}
	return ans;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>k>>m>>n;
	
	long long mul = 1;
	f0(i, 1, k)mul*=10;

	cout<<opw(m, n, mul);

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
