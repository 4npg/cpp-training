// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 1000005

int n;
int64 a[maxn],mxl[maxn],mxr[maxn];

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("threenum");
	cin>>n;	
	f0(i,1,n)cin>>a[i];

	mxl[1] = LLONG_MIN;
	int64 curmx = LLONG_MIN;

	f0(i,2,n){
		curmx = max(curmx,2*a[i-1]);
		mxl[i] = curmx;
	}

	mxr[n] = LLONG_MIN;
	curmx = LLONG_MIN;
	for(int i =n-1;i>=1;--i){
		curmx = max(curmx,5*a[i+1]);
		mxr[i] = curmx;
	}

	int64 ans = LLONG_MIN;
	f0(j,2,n-1){
		ans = max(ans,mxl[j]-3*a[j]+mxr[j]);
	}

	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


