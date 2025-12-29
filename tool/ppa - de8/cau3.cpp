// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "cau3"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (int64)4e18

int n;
int64 s;
int a[maxn];
int ans = 0;

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	 freopen(file".inp", "r", stdin);
	 freopen(file".out", "w", stdout);

	cin>>n>>s;
	f0(i, 0, n-1)cin>>a[i];

	int l = 0;
	int64 sum = 0;

	f0(r, 0, n-1){
		sum += a[r];

		while(sum > s){
			sum -= a[l];
			l++;
		}
		ans += (r-l+1);
	}

	cout<<ans;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
