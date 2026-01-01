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

long long L, R;
vector<int> nto;
bool d[maxn];

void sang(){
	for(int i=2; i*i<maxn; i++){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}

	f0(i, 2, maxn-1)if(!d[i])nto.emplace_back(i);
}

void sangdoan(long long L, long long R){
	memset(d, 0, (R-L+1)*(sizeof(bool)));

	for(int p:nto){
		if(1LL*p*p>R)break;

		long long st = max(1LL*p*p, ((L+p-1)/p)*p);

		for(long long x = st; x<=R; x+=p)d[x-L] = 1;
	}
	
	f0(i, 0, R-L){
		if(!d[i] && L+i>1){
			cout<<L+i<<" ";
		}
	}
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	sang();
	cin>>L>>R;
	sangdoan(L, R);

	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
