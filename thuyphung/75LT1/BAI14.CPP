#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false);cin.tie(nullptr)

int main(){
	fast;
	ll n,k;cin>>n>>k;
	ll mid = (n-1)/2;
	ll ans=0;
	while(k){
		ll x,y;cin>>x>>y;
		ll sum=0;
		ll dx = 1ll*abs(x-mid);
		ll dy = 1ll*abs(y-mid);
		sum = 15*min(dx,dy)+10*(max(dx,dy)-min(dx,dy));
		ans+=sum;
		k--;
	}
	cout<<ans;
}