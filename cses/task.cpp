#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int t;
int arr[5][5] = {
	{1, 2, 9, 10, 25},
	{4, 3, 8, 11, 24},
	{5, 6, 7, 12, 23},
	{16, 15, 14, 13, 22},
	{17, 18, 19, 20, 21}
};

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin>>t;
	while(t--){
		long long x,y; cin>>x>>y;
		x--, y--;
		cout<<arr[x][y]<<'\n';
	}

	cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}