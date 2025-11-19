// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);
#define maxn 200005

int n;
int64 a[maxn], b[maxn];
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>n;
	f0(i,1,n){
		cin>>a[i];
		b[i] = a[i];
	}	

	sort(b+1, b+n+1);

	f0(i,1,n){
		a[i] = lower_bound(b+1,b+n+1,a[i]) - (b+1)+1;
		cout<<a[i]<<" ";
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


