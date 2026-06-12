#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int maxn = 1e5+5;

template<class T> bool maximize(T &a, T b) {
	if(a < b) return a = b, true;
	return false;
}

void solve(){
	int n, k; cin >> n >> k;	

	long long ret = 0, sum = 0;

	for (int i = 0; i < k; ++i) {
		cin >> a[i];
		sum += x;
	}

	maximize(ret, sum);
	for (int i = k; i < n; ++i) {
		cin >> a[i];
		sum += a[i] - a[i-k];
		maximize(ret, sum);
	}

	cout << ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); 

	solve();

	cerr << "\ntime elapsed: " << TIME << "s.\n";
}