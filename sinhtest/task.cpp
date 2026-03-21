#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file "task"

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int a, b;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	freopen(file".inp", "r", stdin);
	freopen(file".out", "w", stdout);

	cin>>a>>b;

	cout<<a+b;

	cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}