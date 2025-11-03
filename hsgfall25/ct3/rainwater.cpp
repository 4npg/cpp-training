// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000006

int n;
int64 a[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("rainwater");	
	cin>>n;
	f0(i,0,n-1)cin>>a[i];

	int l=0, r=n-1;
	int64 lma = 0, rma = 0;
	int64 ans = 0;

	while(l<=r){
		if(a[l]<=a[r]){
			if(a[l]>=lma)lma = a[l];
			else ans += (lma-a[l]);
			++l;
		}else {
			if(a[r]>=rma)rma=a[r];
			else ans +=(rma-a[r]);
			--r;
		}
	}

	cout<<ans;

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


