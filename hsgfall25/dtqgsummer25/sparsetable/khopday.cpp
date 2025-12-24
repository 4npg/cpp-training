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

#define maxn 100005
#define inf (int64)4e18
#define lg 18
#define pb push_back
#define fi first 
#define se second

int n, q;
int64 a[maxn], b[maxn];

int64 gcd(int64 a, int64 b){
	if(b == 0)return a;
	return gcd(b, a%b);
}

int64 d[maxn];

void sub1(){
	while(q--){
		int l, r; cin>>l>>r;
		int64 m = 0;
		f0(i, l, r){
			m = gcd(m, d[i-1]);
		}
		cout<<m<<'\n';
	}
}

int lg2(int64 n){
	return n?63-__builtin_clzll(n):-1;
}

int64 t[lg][maxn];

void init(){
	f0(i, 0, n-1)t[0][i] = d[i];

	f0(j, 1, lg){
		for(int i=0; i + (1<<j) - 1 < n; ++i){
			t[j][i] = gcd(t[j-1][i], t[j-1][i + (1<<(j-1))]);
		}
	}
}

int get(int l, int r){
	int64 k = lg2(r-l+1);
	return gcd(t[k][l], t[k][r - (1<<k) + 1]);
}

youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>n>>q;
	f0(i, 0, n-1)cin>>a[i];
	f0(i, 0, n-1)cin>>b[i];
	
	f0(i, 0, n-1)d[i] = abs(a[i] - b[i]);		

	init();

	while(q--){
		int l, r; cin>>l>>r;
		l--; r--;
		if(l == r){
			cout<<0<<'\n';
			continue;
		}
		cout<<get(l, r)<<'\n';
	}	

	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
