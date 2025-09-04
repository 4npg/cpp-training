// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,q;
const int maxn = 1e6+5;
int64 a[maxn];

bool binarykly(int64 x){
	int l = 0;
	int r = n-1;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(a[mid] == x)return 1;
		if(x>a[mid]){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return 0;
}

int lowerboundkly(int64 x){
	int l = 0;
	int r = n-1;
	int ans = -1;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(a[mid] == x){
			ans = mid;
			r = mid - 1;
		}else if(x>a[mid]){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return (ans!=-1?ans+1:-1);
}

int upperboundkly(int64 x){
	int l = 0;
	int r = n-1;
	int ans = -1;
	while(l<=r){
		int mid = l + (r-l)/2;
		if(a[mid] == x){
			ans = mid;
			l = mid + 1;
		}else if(x>a[mid]){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	return (ans!=-1?ans+1:-1);
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	f0(i,0,n-1)cin>>a[i];
	while(q--){
		int t;
		int64 x;
		cin>>t>>x;
		if(t==1){
			cout<<((binarykly(x)?"YES":"-1"))<<'\n';
		}else if(t==2){
			cout<<(lowerboundkly(x))<<'\n';
		}else {
			cout<<upperboundkly(x)<<'\n';
		}
	}
}


