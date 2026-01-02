// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define con_meo_dua_leo int32_t main
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int i = (a); i <= (b);++i)
#define fd(i,a,b) for(int i = (a); i >= (b);--i)
#define file "cau1"

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1
#define lg 20
#define inf (long long)4e18
#define mod (long long)(1e9+7)

long long a, b, c;


long long mul(long long a, long long b){
	a %= mod;
	b %= mod;
	if(a < 0) a += mod;
	if(b < 0) b += mod;
	return (a*b)%mod;
}

void sub1(){
	cout<<max({mul(a, b), mul(a, c), mul(b, c)});
	//cout<<max({(a%mod*b%mod)%mod, (a%mod*c%mod)%mod, (b%mod*c%mod)%mod});
}

void sub2(){
	vector< pair<long long, long long> > p = {
		{a, b}, {a, c}, {b, c}
	};

	int bt = -2;
	long double bl = -1e36;
	pair<long long, long long> bp = {0, 0};

	for(auto &node:p){
		long long x = node.first;
		long long y = node.second;
		long long dau;

		if(x == 0 || y == 0)dau = 0;
		else if((x>0 && y>0) || (x<0 && y<0))dau = 1;
		else dau = -1;

		if(dau == 1){
			long double val = logl(fabsl(x)) + logl(fabsl(y));
			if(bt < 1 || (bt == 1 && val > bl)){
				bt = 1;
				bl = val;
				bp = node;
			}
		}else if(dau == 0){
			if(bt < 0){
				bt = 0;
				bp = node;
			}
		}else{
			long double val = logl(fabsl(x)) + logl(fabsl(y));
			if(bt == -1){
				if(val < bl){
					bl = val;
					bp = node;
				}
			}else if(bt < -1){
				bt = -1;
				bl = val;
				bp = node;
			}
		}
	}
	
	cout<<mul(bp.first, bp.second);
}

con_meo_dua_leo(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	// freopen(file".inp", "r", stdin);
	// freopen(file".out", "w", stdout);

	cin>>a>>b>>c;

	sub2();
	
	cerr<<"\ntime elapsed: "<<TIME <<"s.\n";
}
