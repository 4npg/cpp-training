#include<bits/stdc++.h>
using namespace std;

#define TIME (1.0*clock()/CLOCKS_PER_SEC)
#define file ""

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define maxn 100005
#define inf (long long)4e18

int n;
int a[maxn], b[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); 

	cin >> n;

	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 0; i < n; i++){
		cin>>b[i];
	}

	long long ans = inf;

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(i == j)continue;
			ans = min(ans, 1LL*abs(a[i] + b[j]));
		}
	}

	cout<<ans;

	cerr << "\ntime elapsed: "<<TIME<<"s.\n";
}