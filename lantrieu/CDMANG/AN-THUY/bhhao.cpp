// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) freopen(name".inp","r",stdin);freopen(name".out","w",stdout);

int n,ans;

int sum(int64 x){
	int s = 0;
	while(x>0){
		s += x%10;
		x/=10;
	}
	return s;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	file("BHHAO");
	cin>>n;
	f0(i,0,n-1){
		int64 a;cin>>a;
		if(sum(a)==6||sum(a)==28)ans++;
	}
	cout<<ans;
	cerr << "time elapsed: "<<TIME <<"s.\n";
}


