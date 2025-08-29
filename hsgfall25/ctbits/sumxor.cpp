// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)
#define bitmask(mask,i) ((mask>>i)&1)

int64 b;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>b;
	if(b==0){
		cout<<1;
		return 0;
	}
	int64 ans = 0;
	int hi = 63 - __builtin_clzll(b);
	f0(i,0,hi){
		if(bitmask(b,i)==0)ans++;
	}
	cout<<(1ll<<ans);
}


