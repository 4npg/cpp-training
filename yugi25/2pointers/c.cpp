#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

const int maxn = 1e6+5;

long long a[maxn], b[maxn];

#define DATA vector<int>


void solve(){
 	long long n, m; cin >> n >> m;
 	for (int i = 0; i < n; ++i) cin >> a[i];
 	for (int i = 0; i < m; ++i) cin >> b[i];

 	DATA ret(m, 0);

 	int i = 0, j = 0;	
 	while (j<m) {
 		while (i<n && a[i] < b[j])i++;
 		ret[j] = i; j++;
 	}

 	for (auto &x:ret) cout << x << " ";
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); 

    solve();

    cerr << "\ntime elapsed: " << TIME << "s.\n";
}