// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 10004

int n;
int a[maxn], b[maxn], c[maxn];
int cnt;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	//file("TRIANGLE");
	cin>>n;	
	f0(i,0,n-1)cin>>a[i];
	f0(i,0,n-1)cin>>b[i];
	f0(i,0,n-1)cin>>c[i];

	sort(a,a+n);
	sort(b,b+n);
	sort(c,c+n);


	f0(i,0,n-1){
		f0(j,0,n-1){
			int s = a[i] + b[j];
			int p = lower_bound(c,c+n,s)-c;
			cnt += p;
		}
	}

	cout<<cnt;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


