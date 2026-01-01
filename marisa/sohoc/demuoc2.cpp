// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file ""

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

int q;
int d[maxn];
vector<int> nto;

void sang(){

	for(int i=2; i*i<maxn; i++){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}

	f0(i, 2, maxn-1){
		if(!d[i])nto.emplace_back(i);
	}
}

int cnt(long long x){
	int dem = 1;

	for(int &p:nto){
		if(1LL*p*p > x)break;
		if(x%p == 0){
			int cntt = 0;
			while(x%p == 0){
				x /= p;
				cntt++;
			}
			dem *= (cntt+1);
		}
	}
	if(x>1)dem *= 2;
	return dem;
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	sang();

	cin>>q;
	while(q--){
		long long x; cin>>x;
		cout<<cnt(x)<<'\n';
	}

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
