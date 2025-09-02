// author : anphung >> npkly
#include<bits/stdc++.h>
using namespace std;
#define int64 long long
#define f0(i,a,b) for(int (i)=(a);(i)<=(b);++i)

int n,q;
const int maxn = 1e5+5;
int a[maxn];
int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>q;
	f0(i,0,n-1)cin>>a[i];
	while(q--){
		int t,x;
		cin>>t>>x;
		auto itlb = lower_bound(a,a+n,x);
		auto itub = upper_bound(a,a+n,x);
		if(t==1){
			if(itlb==a+n)cout<< -1 <<'\n';
			else cout<<*itlb<<'\n';
		}else if(t==2){
			if(itub==a+n)cout<< -1 <<'\n';
			else cout<<*itub<<'\n';
		}else if(t==3){
			if(itub==a)cout<< -1 <<'\n';
			else cout<<*(itub-1)<<'\n';
		}else if(t==4){
			if(itlb==a)cout<< -1 <<'\n';
			else cout<<*(itlb-1)<<'\n';
		}else {
			cout<<itub-itlb<<'\n';
		}
	}	
}


