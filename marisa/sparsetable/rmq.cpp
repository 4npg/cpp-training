// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 100005
#define lg 18

int n, q;
int64 a[maxn];
int t[lg][maxn];

int lg2(int x){
	return x? 31 - __builtin_clz(x) : -1;
}

void init(){

	f0(i, 0, n-1)t[0][i] = i;

	f0(j, 1, lg){
		for(int i=0; i+(1<<j)-1<n; i++){
			int x = t[j-1][i];
			int y = t[j-1][i + (1<<(j-1))];
			t[j][i] = (a[x] <= a[y] ? x : y);
		}
	}

}

int64 get(int l, int r){
	int k = lg2((r-l+1));
	int x = t[k][l];
	int y = t[k][r-(1<<k)+1];
	return (a[x] <= a[y] ? x : y);
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;

	f0(i, 0, n-1)cin>>a[i];

	init();

	while(q--){
		int l, r; cin>>l>>r;
		l--; r--;
		cout<<get(l, r)+1<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
