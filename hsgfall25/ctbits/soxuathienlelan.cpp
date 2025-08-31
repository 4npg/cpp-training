// author : anphung
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n;
	int64 ans = 0;
	f0(i,0,n-1){
		int64 x;cin>>x;
		ans = (ans ^ x);
	}
	cout<<ans;
}


