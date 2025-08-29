// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

const int mod = 1e9+7;

int64 ipow(int64 a,int64 b){
	int64 ans = 1;
	while(b){
		if(b&1)ans = (ans*a)%mod;
		a = (a*a)%mod;
		b>>=1;
	}
	return ans;
}

int t;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		int64 a,b;
		cin>>a>>b;
		cout<<ipow(a,b)<<'\n';
	}	
}


