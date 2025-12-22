// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file ""

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 200005
#define lg 18

int n, q;
int64 a[maxn], t[lg][maxn];
int lg2[maxn];

void pre(){
	lg2[1] = 0;

	f0(i, 2, maxn-1){
		lg2[i] = lg2[i/2] + 1;
	}
}

void init(){
	f0(i, 1, n)t[0][i] = a[i];

	f0(j, 1, lg)
		for(int i = 1; i + (1<<j)-1 <= n; ++i){
			t[j][i] = min(t[j-1][i], t[j-1][i+(1<<(j-1))]);
		}
}

int64 get(int l, int r){
	int64 k = lg2[r-l+1];
	return min(t[k][l], t[k][r-(1<<k)+1]);
}
youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 1, n)cin>>a[i];

	pre();
	init();
	
	while(q--){
		int l, r;
		cin>>l>>r;
		cout<<get(l, r)<<'\n';
	}
	cerr << "time elapsed: "<<TIME <<"s.\n";
}
