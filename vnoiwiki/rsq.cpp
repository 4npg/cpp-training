// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file ""

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 200005
#define lg 18

int n, q;
int64 a[maxn], t[lg][maxn];
int lg2(int64 n){
	return n?63-__builtin_clzll(n):-1;
}

void init(){
	f0(i, 1, n)t[0][i] = a[i];

	f0(j, 1, lg){
		for(int i=1; i+(1<<j)-1<=n; i++){
			t[j][i] = t[j-1][i] + t[j][i+(1<<(j-1))];
		}
	}
}

int get(int l, int r){
	int len = r-l+1;
	int sum = 0;
	for(int j=0; (1<<j) <= len; ++j){
		if(len>>j & 1){
			sum = sum + t[j][l];
			l = l + (1<<j);
		}
	}
	return sum;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;

	f0(i, 1, n)cin>>a[i];

	init();

	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<get(l, r)<<'\n';
	}
	f0(i, 1, n)cin>>a[i];



	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
