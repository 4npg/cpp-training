// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n;
int64 s;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n>>s;
	vector<int64> a(n);

	f0(i,0,n-1)cin>>a[i];

	int64 sum = 0;
	int lo = 0;
	int res = 1e9;

	f0(hi,0,n-1){
		sum+=a[hi];
		while(sum>=s){
			res = min(res,hi-lo+1);
			sum-=a[lo];
			lo++;
		}
	}

	cout<<res;
	
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


