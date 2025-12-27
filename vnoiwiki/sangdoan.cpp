// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define int64 long long
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
#define inf (int64)4e18
#define pb push_back

vector<int> nto;
bool d[maxn];
int64 l, r;

void sang(){
	d[0] = d[1] = 1;

	for(int i=2; i*i<maxn; i++){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}

	f0(i, 2, maxn-1){
		if(!d[i])nto.pb(i);
	}
}

void sangdoan(int64 l, int64 r){
	memset(d, 0, (r-l+1)*sizeof(bool));

	for(auto p:nto){
		if(1ll*p*p>r)break;

		int64 st = max(1ll*p*p, ((l+p-1)/p)*p);

		for(int64 x = st; x<=r; x+=p){
			d[x-l] = 1;
		}
	}

	f0(i, 0, r-l){
		if(!d[i] && l+i>1){
			cout<<l+i<<" ";
		}
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>l>>r;

	sang();
	sangdoan(l, r);

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
