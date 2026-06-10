#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int inf = 1e9+7;
const int mod = 1e9+7;
const int maxn = 1e6+5;

template <class X, class Y> bool maximize(X &a, Y b){
    if(a < b) return a = b, true;
    return false;
}

template <class X, class Y> bool minimize(X &a, Y b){
    if(a > b) return a= b, true;
    return false;
}

#define DATA vector<long long>
#define miniDATA vector<int>

bool d[maxn];
int mindiv[maxn];

void sang(){
	d[0] = d[1] = 1;

	for(int i = 2; i*i<maxn; ++i){
		if(mindiv[i]) continue;
		mindiv[i] = i;
		for(int j = i+i; j<maxn; j+=i) {
			mindiv[j] = i;
		}
	}
}

int sub1(int n) {
	if(n == 1)return 1;
	miniDATA prep;
	int lastDiv = 1;
	int cnt = 0;

	while( n != 1 ){
		if(mindiv[n] != lastDiv) {
			if(cnt)prep.emplace_back(cnt);
			cnt = 0;
		}
		++cnt;
		lastDiv = mindiv[n];
		n /= mindiv[n];
	}
	if(cnt)prep.emplace_back(cnt);
	int ret = 1;
	for(auto i : prep)ret *= (i+1);
	return ret;
}

void solve(){
	sang();
	int q; cin >> q;

	while ( q-- ) {
		int n; cin >> n;
		cout << sub1(n) << '\n';
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); 
    
    solve();

    cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}