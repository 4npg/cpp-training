// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define i_love_Hoang_Ngan int32_t main
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define fd(i,a,b) for(int (i)=(a);(i)>=(b);--i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

// mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// int Rand(int l, int r){
// 	return l+rng()%(r-l+1);
// }

#define maxn 1000006
#define pb push_back
#define mod 20232024

int64 n, res = 1;
bool d[maxn];
vector<int> nto;
vector<int> tso;
void sang(){
	d[0] = d[1] = 1;

	for(int i=2; i*i<maxn; i++){
		if(d[i] == 0){
			for(int j=i*i; j<maxn; j+=i)d[j] = 1;
		}
	}

	f0(i, 2, maxn-1)if(!d[i])nto.pb(i);
}



int64 opw(int64 a, int64 b){
	int64 ans = 1;
	while(b){
		if(b&1)ans = (ans*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return ans;
}

i_love_Hoang_Ngan(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	sang();

	cin >> n;
	int64 orig = n;

	for(auto &p:nto){
	    if((int64)p * p > n) break;
	    if(n % p == 0){
	        while(n % p == 0) n /= p;
	        tso.pb(p);
	    }
	}

	if(n > 1 && n < orig) tso.pb(n);

	for(auto &x : tso){
	    res = res * (opw(3, x) + x) % mod;
	}
	cout << res;


	cerr << "time elapsed: "<<TIME <<"s.\n";
}




