// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

long double s;

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>s;
	long double lo = 0;
	long double hi = sqrt(s);
	for(int it=0;it<60;it++){
		long double mid=(lo+hi)/2;
		long double val = mid*mid + sqrt(mid);
		if(val<s)lo=mid;
		else hi = mid;
	}
	cout<<fixed<<setprecision(6)<<(double)((lo+hi)/2);
}


