// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "task"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, k;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".ans", "w", stdout);

	cin>>n>>k;

	int mn = k*(k+1)/2;
	if(n < mn)return cout<<-1, 0;

	int ans = (n-mn)%k;

	cout<<(ans == 0?k-1:k);

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
