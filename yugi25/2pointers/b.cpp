#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int maxn = 1e5+5;

long long a[maxn], b[maxn];
string ret = "";

void solve(){
 	long long n; cin >> n;
 	for (int i = 0; i < n; ++i) cin >> a[i];
 	long long m; cin >> m;
 	for (int i = 0; i < m; ++i) cin >> b[i];

 	int i = 0, j = 0;
 	while (i<n&&j<m) {
 		if(a[i] <= b[j]) {
 			cout << a[i++] << ' ';
 			ret += 'a';
 		} else {
 			cout << b[j++] << ' ';
 			ret += 'b';
 		}
 	}

 	while (i<n) {
 		cout << a[i++] << ' ';
 		ret += 'a';
 	}
 	while (j<m) {
 		cout << b[j++] << ' ';
 		ret += 'b';
 	}

 	cout << '\n' << ret;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}