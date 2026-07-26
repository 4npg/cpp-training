#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int MAX = 10010;
const int BASE = 256;
const int MOD = (int)1e9+2277;
const int maxn = 1e5+5;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

char s[MAX];
long long hs[maxn];
long long pw[maxn];


int getkey(char c){
	return c - '0';
}

template<class T> T opw(T a, T b){
	T ans = 1;
	while ( b > 0 ) {
		if ( b&1 ) ans = (ans * a)%MOD;
		a = (a * a)%MOD;
		b >>= 1;
	}
	return ans;
}

namespace bai1{

	template<class T> T  mulmod(T a, T b){
		T ans = 0;
		while (b){
			if (b & 1) ans = ans+a;
			a = a + a;
			b >>= 1;
		}
		return ans;
	}

	int n, k;
	char s[MAX][MAX];
	long long pw[MAX];
	long long hs[MAX];
	int res = 0;


	void solve(){
		cin >> n >> k;

		pw[0] = 1;

		for (int i = 0; i < n; i++){
			s[i][0] = ' ';
			for (int j = 1; j <= k; j++){
				cin >> s[i][j];
			}
		}

		for(int i = 1; i<=k; i++) {
			pw[i] = pw[i-1] * BASE % MOD;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 1; j <= k; j++) {
				hs[i] = (hs[i] + 1LL*s[i][j]*pw[j-1])%MOD;
			} 
		}


		for (int i = 0; i < n; i++) {
			for (int j = i+1; j < n; j++) {
				if(hs[i] == hs[j]) res++;
			} 
		}

		cout << res;
	}
}


void coban(){
	// int n, k; cin >> n >> k;

	// for (int i = 0; i < n; i++){
	// 	for (int j = 0; j < k; j++)
	// 		cin >> s[j][i];
	// }

	pw[0] = 1;

	int k; cin >> k;
	
	s[0] = ' ';

	for (int i = 1; i <= k; i++){
		pw[i] = 1LL * pw[i-1] * BASE % MOD;
	}

	for (int i = 1; i <= k; i++) {
		cin >> s[i];
		cout << s[i] << ' ' << (int)s[i] << '\n';
	} 

	// for(char c='a'; c<='z'; c++){
	// 	cout << c << ' ' << getkey(c) << '\n';
	// }
	

	long long hash = 0;

	// cout << s;

	// cout << '\n';

	int n = k;

	for( int i = 1; i <= n; i++){
		// hash = (hash + (1LL * s[i] * opw(1LL*256, 1LL*(i-1)))%MOD)%MOD;

		hash = (hash + 1LL * s[i] * pw[i-1])%MOD;

		// cout << s[i] << ' ' << i-1 << '\n';
	}

	cout << hash;
}

// cho n xau ky tu s1 s2,..., sn co cung do dai k. dem so cap xau si = sj 


int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

 	bai1::solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}