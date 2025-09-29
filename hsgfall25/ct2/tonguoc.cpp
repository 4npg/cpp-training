// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define TIME (1.0 * clock() / CLOCKS_PER_SEC)
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define file(name) if(fopen(name".inp","r")){ freopen(name".inp","r",stdin);freopen(name".out","w",stdout);}


int64 a,b;

int64 gcd(int64 a,int64 b){
	if(b==0)return a;
	return gcd(b,a%b);
}

void sub1(){
	int64 ans = 0;
	b = b/3;
	int64 g = gcd(a,b);
	for(int64 i = 1;i*i<=g;i++){
		if(g%i==0){
			ans+=i;
			if(g/i!=i)ans+=g/i;
		}
	}
	cout<<ans;
}


int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);

	cin>>a>>b;
	if(b%3!=0){
		cout<<0;
		return 0;
	}else{
		sub1();
	}

	cerr << "time elapsed: "<<TIME <<"s.\n";
}


