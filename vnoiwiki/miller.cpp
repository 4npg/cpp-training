#include<bits/stdc++.h>
using namespace std;

#define file ""
#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define maxn = 1e6+5;
#define DATA vector<long long>
#define miniDATA vector<int>

template<class T> T mulmod(T a, T b, T mod){
	T ans = 0;
	while(b){
		if(b&1)ans = (ans + a)%mod;
		a = (a + a)%mod;
		b>>=1;
	}
	return ans;
}

template<class T> T opw(T a, T b, T mod){
	T ans = 1;
	while(b){
		if(b&1)ans = mulmod(ans, a, mod);
		a = mulmod(a, a, mod);
		b >>= 1;
	}
	return ans;
}

template<class T> bool test(T a, T n, T k, T m){
	T mod = opw(a, m, n);
	if( mod == 1 || mod == n-1)return 1;

	for(int l = 1; l < k; ++l){
		mod = mulmod(mod, mod, n);
		if(mod == n-1)return 1;
	}
	return 0;
}

template<class T> bool miller(T n){
	static DATA checkset = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};

	for(auto &a : checkset){
		if( n == a )return 1;
	}

	if( n < 41 ) return 0;
	T k = 0, m = n-1;

	while(m % 2 == 0){
		m /= 2;
		k++;
	}

	for(auto &a : checkset){
		if(!test(a, n, k, m))return 0;
	}
	return 1;
}

void solve(){
	// long long n = uniform_int_distribution<long long>(1, 1000000000)(rng);
	long long n; cin >> n;
	// cout << "n = " << n << '\n';
	cout << (miller(n)?"YES":"NO") << '\n';
}

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);

	solve();

	cerr << "\ntime elapsed: " << TIME << "s.\n";
}