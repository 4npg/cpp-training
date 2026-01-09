// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int i = (a); i <=(b); ++i)
#define fd(i, a, b) for(int i = (a); i >=(b); --i)
#define file "lcd"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//long long Rand(long long l, long long r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int n, m;
int a[maxn];
long long difk[maxn];
long long difb[maxn];

void addsg(int L, int R, long long k, long long b){
	if(L>R)return;
	difk[L] += k;
	difk[R+1] -= k;
	difb[L] += b;
	difb[R+1] -= b;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>m;
	f0(i, 1, n)cin>>a[i];

	long long base = 0;

	f0(i, 1, n-1){
		int u = a[i];
		int v = a[i+1];

		int ci = (v-u+m)%m;
		if(ci == 0)ci = m;
		base += ci;

		if(ci <= 1)continue;

		int len = ci - 1;
		int L = v - (ci - 2);
		int R = v;

		if(L>=1){
			addsg(L, R, +1, (ci - 1 - v));
		}else{
			addsg(1, R, +1, (ci-1-v));
			addsg(L+m, m, +1, (ci-1-v-m));
		}
	}

	long long ans = inf;
	long long curk = 0, curb = 0;
	f0(x, 1, m){
		curk += difk[x];
		curb += difb[x];
		ans = min(ans, base - (curk*x+curb));
	}

	cout<<ans;

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
