// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}

int64 a,b;

int64 ipow(int64 a, int64 b){
	int64 ans = 1;
	while(b){
		if(b&1)ans = ans*a;
		a*=a;
		b>>=1;
	}
	return ans;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	cin>>a>>b;

	cout<<ipow(a,b)<<" "<<pow(a,b);	

	cerr << "time elapsed: "<<TIME <<"s.\n";
}





