// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int t;
int64 solve(int64 n){
	n = (n+1)/2;
	return (n*(2*n+1)*(2*n-1))/3;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>t;
	while(t--){
		int64 n;
		cin>>n;
		cout<<solve(n)<<'\n';
	}	

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


