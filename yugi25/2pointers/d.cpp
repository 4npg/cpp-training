#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template<class T> bool maxi(T &a, T b){ if (a < b) return a = b, true; return false; }
template<class T> bool mini(T &a, T b){ if (a > b) return a = b, true; return false; }

const int maxn = 1e6+5;
const int MAX = 1000100
const int BASE = 256;
const int MOD = (int)1e9+2277;


namespace sub1{	

	int gen(int l, int r){
		return uniform_int_distribution<int>(l, r)(rng);
	}

	char s[MAX][MAX];
	int n, k;
	
	bool equal(int i, int j){
		for (int t= 1; t < k; t++){
			if(s[i][t] != s[j][t])return false;
		}
		return true;
	}

	



	void solve(){
		// hs[i] = mã hash của xâu s[i];
		// pw[i] = 256^i

		// chuẩn bị trước: tính mảng BASE
		pw[0] = 1;
		for (int i = 1; i < MAX; i++) pw[i] = 1LL * pw[i-1] * BASE % MOD;

		// tính mã hash của n xâu

		for (int i = 1; i <= n; i++) {
			hs[i] = 0;
			for (int j = 1; j <= k; j++) hs[i] = (hs[i] + 1LL * s[i][j] * pw[j-1])%MOD;
		}

		int res = 0;
		for( int i = 1; i <= n ; i++)
			for(int j = i+1; j <= n; j++)
				if (hs[i] == hs[j]) res++;
	}
}


namespace bai2{

	int gen(int l, int r){
		return uniform_int_distribution<int>(l, r)(rng);
	}

	int pw[MAX], invPw[i];

	// pw[i] = 256^1, invPw[i] = (256^i)^(MOD -2) = 256^(MOD-2)^i

	int opw(int x, int k){
		int res = 1, mul = x;
		while (k > 0){
			if (k & 1) res = 1LL * res * mul % MOD;
			mul = 1LL * mul * mul % MOD;
			k >>= 1;
		}
		return res;
	}

	// chuẩn bị mảng pw, invpw
	int invBase = power(BASE, MOD -2);
	pw[0] = invPw[0] = 1;
	for (int i = 1; i < MAX; i++){
		pw[i] = 1LL * pw[i-1] * BASE % MOD;
		invPw[i] = 
	}
}

void solve(){
	sub1::solve();

}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	solve();

	cerr << "\ntime elapsed: " << TIME << "s.\n";
}