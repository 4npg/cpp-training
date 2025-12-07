// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define inf (int64)1e18

int64 n;

int32_t main(){
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin>>n; 
	int64 xma=-inf, xmi=inf, yma=-inf, ymi=inf;

	f0(i, 0, n-1){
		int64 x, y;cin>>x>>y;
		yma = max(y,yma);
		xma = max(x,xma);
		ymi = min(y,ymi);
		xmi = min(x,xmi);

	}
	int64 c = max(xma-xmi, yma-ymi);

	cout<<c*c;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


