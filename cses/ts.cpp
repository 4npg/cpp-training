#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int inf = 1e9+7;
const int mod = 1e9+7;
const int maxn = 1e6+5;

template <class X, class Y> bool maximize(X &a, Y b){
	if(a < b)return a = b, true;
	return false;
}

template <class X, class Y> bool minimize(X &a, Y b){
	if(a > b) return a = b, true;
	return false;
}


int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int bla = uniform_int_distribution<int>(1, 100)(rng);

	cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}