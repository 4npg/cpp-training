// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "VIRUS"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 20

int n, t;

int64 opw(int64 a, int64 b){
	int64 ans = 1;

	while(b){
		if(b&1)ans *= a;
		a *= a;
		b>>=1;
	}
	return ans;
}

int64 mul(int64 a, int64 b){
	int64 ans = 0;
	while(b){
		if(b&1)ans = (ans+a);
		a = (a+a);
		b>>=1;
	}
	return ans;
}

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>t;

	cout<<mul(1ll*n, opw(2*1ll, 1ll*t));
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
