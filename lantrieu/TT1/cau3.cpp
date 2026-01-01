// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
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
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, a[maxn];

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n;
	f0(i, 0, n-1)cin>>a[i];

	int l = 0;
	int ma = 0;

	while(l < n){
		while(l<n && a[l] == 0)l++;
		if(l == n)break;

		int r = l;
		int am = 0;
		int fiam = -1, laam = -1;

		while(r < n && a[r] != 0){
			if(a[r] < 0){
				am++;
				if(fiam == -1)fiam = r;
				laam = r;
			}
			r++;
		}

		if(am%2==0)ma = max(ma, r-l);
		else{
			ma = max(ma, max(r-(fiam+1), laam-l));
		}
		l = r;
	}

	cout<<ma;
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
