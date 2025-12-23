// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define youngboiz_nobug int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i, a, b) for(int (i)=(a); (i)<=(b); ++i)
#define fd(i, a, b) for(int (i)=(a); (i)>=(b); --i)
#define file "CMPR"

//mt19937_64 rng(chrono::system_clock::now().time_since_epoch().count());

//int64 Rand(int64 l, int64 r){
//	return l+rng()%(r-l+1);
//}

#define maxn 1000006
#define pb push_back

int d[maxn];
int cnt[maxn];
int n, q;

void sang(){
	d[0] = 0;
	d[1] = 0;
	for(int i=2; i*i<maxn; i++){
		if(d[i]==0)
		for(int j=i; j<maxn; j+=i)if(d[j]==0)d[j] = i;
	}
	f0(i, 2, maxn-1){
		if(d[i] == 0)d[i] = i;
	}
}


youngboiz_nobug(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	sang();

	cin>>n>>q;

	f0(i, 2, n)cnt[d[i]]++;

	while(q--){
		int64 x; cin>>x;
		if(x<=n)cout<<cnt[x]<<'\n';
		else cout<<0<<'\n';
	}
	cerr << "\ntime elapsed: "<<TIME <<"s.\n";
}
