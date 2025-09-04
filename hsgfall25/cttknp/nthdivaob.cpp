// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int t;

int64 gcd(int64 a,int64 b){
	return (b?gcd(b,a%b):a);
}
int64 lcm(int64 a,int64 b){
	return a/gcd(a,b)*b;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		int64 n,a,b;
		cin>>a>>b>>n;
		int64 lo=1,hi=1e18,ans=-1;
		while(lo<=hi){
			int64 mid = lo + (hi-lo)/2;
			int64 cnt = mid/a + mid/b - mid/lcm(a,b);
			if(cnt>=n){
				ans = mid;
				hi = mid-1;
			}else{
				lo = mid+1;
			}
		}
		cout<<ans<<'\n';
	}
}


