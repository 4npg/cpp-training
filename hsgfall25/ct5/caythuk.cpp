// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 100005
#define inf (int64)2e18

int n, q;
int64 a[maxn];

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n>>q;
	f0(i, 0, n-1)cin>>a[i];

	sort(a, a+n);
	
	while(q--){
		int64 x; int k;
		cin>>x>>k;

		int64 lo = 0, hi = inf;
		while(lo < hi){
			int64 mid = lo + (hi-lo)/2;

			int64 tl = x-mid;
			int64 tr = x+mid;

			auto it1 = lower_bound(a, a+n, tl);
			auto it2 = upper_bound(a, a+n, tr);

			if(it2-it1>=k)hi = mid;
			else lo = mid+1;
		}
		cout<<lo<<'\n';
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


