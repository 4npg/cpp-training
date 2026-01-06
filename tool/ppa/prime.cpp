// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "prime"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define lg 20
#define inf (int64)4e18
#define mod (int64)(1e9+7)

bool d[maxn];
int n, cnt = 0;

void sang(){
	d[0] = d[1] = 1;
	for(int i=2; i*i<maxn; i++){
		if(!d[i])for(int j=i*i; j<maxn; j+=i)d[j] = 1;
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	sang();

	cin>>n;
	f0(i, 0, n-1){
		int x; cin>>x;
		if(!d[x])cnt++;
	}

	cout<<cnt;
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
